/* vsort.c: A simple, external sort/merge
 *
 *      Divides large files into sorted subfiles,
 *      if necessary, then merges them.
 *
 *      OPTIONS:
 *              -i      ignore case
 *              -nW     sort numbers of width W
 *              -r      reverse (descending order)
 *              -v      verbose (display progress)
 *              -N      sort field starts in column N
 *                      (1-based)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <float.h>

#define MAXLINES 100    /* Watch your stack size! */
#define MAXFILES 15
#define MAXNUM DBL_DIG+9

/* Compare function for qsort */
int comp(const void *, const void *);

/* Merge file info */
struct mfile
{
    FILE *f;
    char name[L_tmpnam];
    char line[BUFSIZ];
} files[MAXFILES];

/* Option control flags */
int
    width = MAXNUM,
    fold = 0,
    numeric = 0,
    reverse = 0,
    verbose = 0,
    start_col = 0,
    nfiles = 0;

int main(int argc, char **argv)
{
    int i;
    void sort(void);

    /* Process command-line options */
    for (i = 1; i < argc && *argv[i] == '-'; ++i)
    {
        char *p;

        for (p = argv[i]+1; *p; ++p)
            switch(tolower(*p))
            {
                case 'i':
                    fold = 1;
                    break;
                case 'n':
                    numeric = 1;
                    width = atoi(p+1);
                    if (width <= 0)
                        width = MAXNUM;
                    goto next_arg;
                case 'r':
                    reverse = 1;
                    break;
                case 'v':
                    verbose = 1;
                    break;
                default:
                    if (isdigit(*p))
                        start_col = max(atoi(p)-1,0);
                    else
                        fprintf(stderr,"Bad option: %c\n",*p);
                    goto next_arg;
            }
next_arg:   /* Break inner loop to cycle on outer */
        ;
    }

    if (verbose)
    {
        /* Display options */
        fprintf(stderr,"Start column = %d.\n",start_col+1);

        if (numeric)
            fprintf(stderr,"Sorting numerically (width = %d).\n",width);
        else if (fold)
            fputs("Case ignored in comparisons.\n",stderr);

        if (reverse)
            fputs("Sorting in descending order.\n",stderr);
    }

    /* Redirect standard input */
    if (i < argc && freopen(argv[i],"r",stdin) == NULL)
    {
        fprintf(stderr,"Can't open %s.\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    sort();
    return EXIT_SUCCESS;
}

void sort(void)
{
    static char buf[BUFSIZ], *lines[MAXLINES];
    int i, nlines, min_idx;
    int merge_flag = 0;
    void make_mfile(char **, int, int);
    void remove_temps(void);

    if (verbose)
        fputs("Reading file...\n",stderr);

    /* Register exit handler */
    atexit(remove_temps);

    /* Read input lines */
    for (nlines = 0; fgets(buf,BUFSIZ,stdin); ++nlines)
    {
        if (nlines == MAXLINES ||
            (lines[nlines] = malloc(strlen(buf)+1))
              == NULL)
        {
            /* Store in temporary merge file */
            merge_flag = 1;
            make_mfile(lines,nlines,nfiles++);

            lines[nlines = 0] = malloc(strlen(buf)+1);
        }
        strcpy(lines[nlines],buf);
    }

    if (merge_flag)
    {
        /* Form last merge file from remaining lines */
        make_mfile(lines,nlines,nfiles++);

        if (verbose)
            fprintf(stderr,"Merge phase (%d runs)\n",
                    nfiles);

        /* Open temporary files */
        for (i = 0; i < nfiles; ++i)
        {
            files[i].f = fopen(files[i].name,"r");
            if (files[i].f == NULL)
            {
                fputs("Temporary file error.\n",stderr);
                exit(EXIT_FAILURE);
            }

            /* Read first line */
            fgets(files[i].line,BUFSIZ,files[i].f);
        }

        /* Do the merge */
        while (nfiles)
        {
            /* Find next output line */
            for (min_idx = 0, i = 1; i < nfiles; ++i)
            {
                char *s1 = files[i].line;
                char *s2 = files[min_idx].line;
                if (comp(&s1,&s2) < 0)
                    min_idx = i;
            }

            /* Print it */
            fputs(files[min_idx].line,stdout);

            /* Get the next line from this file */
            if (fgets(files[min_idx].line,
                      BUFSIZ,
                      files[min_idx].f)
                == NULL)
            {
                /* This file is finished */
                fclose(files[min_idx].f);
                if (verbose)
                    fputs("Deleting temporary file\n",
                            stderr);
                remove(files[min_idx].name);
                files[min_idx] = files[--nfiles];
            }
        }
    }
    else
    {
        /* Sort singleton file and print it*/
        if (verbose)
            fputs("Sorting...\n",stderr);
        qsort(lines,nlines,sizeof lines[0],comp);
        for (i = 0; i < nlines; ++i)
        {
            fputs(lines[i],stdout);
            free(lines[i]);
        }
    }
}

int comp(const void *xp, const void *yp)
{
    char *x = *(char **)xp, *y = *(char **)yp;
    int result;

    if (numeric)
    {
        double diff;
        char xtemp[MAXNUM+1], ytemp[MAXNUM+1];

        /* Compare numbers */
        sprintf(xtemp,"%-.*s",width,x+start_col);
        sprintf(ytemp,"%-.*s",width,y+start_col);
        diff = atof(xtemp) - atof(ytemp);
        result = (diff < 0.0)
                   ? -1
                   : (diff > 0.0) ? 1 : 0;
    }
    else if (fold)
        result = stricmp(x+start_col,y+start_col);
    else
        result = strcmp(x+start_col,y+start_col);

    return reverse ? -result : result;

}

void make_mfile(char **lin, int nl, int nf)
{
    FILE *f;
    int i;

    if (nl == 0)
        return;

    /* Sort lines and store in a temporary file */
    tmpnam(files[nf].name);
    if ((f = fopen(files[nf].name,"w")) == NULL)
    {
        fputs("Can't open temporary file.\n",stderr);
        exit(EXIT_FAILURE);
    }
    qsort(lin,nl,sizeof lin[0],comp);

    if (verbose)
        fprintf(stderr,
                "Writing temporary file %d...\n",
                nf);
    for (i = 0; i < nl; ++i)
    {
        fputs(lin[i],f);
        free(lin[i]);
    }
    fclose(f);
    files[nf].f = NULL;
}

void remove_temps(void)
{
    int i;

    /* Delete stragglers at exit */
    for (i = 0; i < nfiles; ++i)
    {
        if (files[i].f)
            fclose(files[i].f);
        if (verbose)
            fputs("Deleting temporary file.\n",
                    stderr);
        remove(files[i].name);
    }
}
