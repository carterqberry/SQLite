/* view.c:  A simple 4-way-scrolling file browser */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "ansi.h"  /* Non-portable */

#define NROWS   24 /* Height of screen - 1*/
#define NCOLS   79 /* Width of screen - 1 */
#define HORIZ   32 /* Horiz. scroll increment */

/* # of screens deep in file you can go - watch stack size! */
#define MAXSTACK 100

/* Buffer for current screen */
static char Screen[NROWS][BUFSIZ];

static size_t
  Nlines,     /* Number of lines to display */
  Offset = 0; /* Horizontal display offset */

static void read_a_screen(FILE *);
static void display(void);
static void display_banner(char *, size_t);

int main(int argc, char *argv[])
{
    FILE *f;
    char *file;
    fpos_t top_pos, stk_[MAXSTACK];
    size_t stkptr_ = 0;
    int c;

    /* Open input file */
    if (argc == 1 || (f = fopen(argv[1],"r")) == NULL)
    {
        fputs("No such file.\n",stderr);
        return EXIT_FAILURE;
    }
    file = argv[1];

top:
    /* Display initial screen */
    rewind(f);
    fgetpos(f,&top_pos);
    read_a_screen(f);
    display();
    display_banner(file,stkptr_+1);

    for (;;)
    {
        c = getchar();
        switch(toupper(c))
        {
            case 'D':   /* Display the next screen */
                if (!feof(f))
                {
                    PUSH(top_pos);
                    fgetpos(f,&top_pos);
                    read_a_screen(f);
                    display();
                }
                break;

            case 'U':   /* Display the previous screen */
                if (stkptr_ > 0)
                {
                    top_pos = POP();
                    fsetpos(f,&top_pos);
                    read_a_screen(f);
                    display();
                }
                break;

            case 'T':   /* Display first screen */
                stkptr_ = 0;
                goto top;

            case 'B':   /* Display last screen */
                while (!feof(f))
                {
                    PUSH(top_pos);
                    fgetpos(f,&top_pos);
                    read_a_screen(f);
                }
                display();
                break;

            case 'L':   /* Scroll left */
                if (Offset > 0)
                {
                    Offset -= HORIZ;
                    display();
                }
                break;

            case 'R':   /* Scroll right */
                if (Offset < BUFSIZ-HORIZ)
                {
                    Offset += HORIZ;
                    display();
                }
                break;

            case 'Q':   /* Quit */
            case 'X':
                cls();
                return EXIT_SUCCESS;
        }
        
        if (c != '\n')
            (void) getchar();  /* Eat '\n' */
        display_banner(file,stkptr_+1);
    }
}

static void read_a_screen(FILE *f)
{
    int i;

    clearerr(f);
    for (
         i = 0;
         i < NROWS && fgets(Screen[i],BUFSIZ,f);
         ++i
        )
        Screen[i][strlen(Screen[i])-1] = '\0';
    Nlines = i;
}

static void display(void)
{
    int i;

    /* Display a screenful of text */
    cls();
    for (i = 0; i < Nlines; ++i)
        if (Offset < strlen(Screen[i]))
        {
            setcur(i+2,1);
            fprintf(stderr,"%.*s",NCOLS,Screen[i]+Offset);
        }
}

static void display_banner(char *fname, size_t screen_num)
{
    char banner[NCOLS+1];

    /* Display banner line in reverse video */
    setcur(1,1); rvs();
    sprintf(banner,
      "File: %s     Screen: %d     Columns: %d-%d",
      fname,screen_num,Offset+1,Offset+NCOLS);
    strcat(banner,"        Command? ");
    fprintf(stderr,"%-*.*s",NCOLS,NCOLS,banner);
    reset();
    setcur(1,strlen(banner)+1);
}
