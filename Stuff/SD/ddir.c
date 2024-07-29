#include <dirent.h>
#include <dir.h>
#include <stdio.h>

/* ddir.c:  Remove subdirectory tree */
int main(int argc, char **argv)
{
    void rd(char *);	// does the work
    char *old_path = getcwd(NULL,64);
  
    /* Delete the directories */
    while (--argc)
        rd(*++argv);

    /* Restore directory */
    chdir(old_path);
    return 0;
} 

void rd(char* dir)
{
    void erase_dir(void);

    /* Log onto the directory to be deleted */
    chdir(dir);

    /* Delete all normal files via OS shell */
    system("del /q *.* > nul");

    /* Delete any remaining entries */
    erase_dir();

    /* Remove the directory from its parent */
    chdir("..");
    rmdir(dir);
}

void erase_dir()
{
    DIR *dirp;
    struct dirent *entry;
    struct stat finfo;
    
    /* Erase the current directory */
    dirp = opendir(".");
    while ((entry = readdir(dirp)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;
        stat(entry->d_name,&finfo);
        if (finfo.st_mode & S_IFDIR)
            rd(entry->d_name);      /* Subdirectory */
        else
        {
            /* Enable delete of file, then do it */
            chmod(entry->d_name,S_IWRITE);
            unlink(entry->d_name);
        }
    }
    closedir(dirp);
}

