#include <stdio.h>
#include <signal.h>

int main()
{
    char buf[BUFSIZ];
    int i;

    /* Ignore keyboard interruptions */
    signal(SIGINT,SIG_IGN);

    while (gets(buf))
        puts(buf);

    /* Restore default attention key handling
       so the user can abort form the keyboard */
    signal(SIGINT,SIG_DFL);
    for (i = 1; ; ++i)
        printf("%d%c",i,(i%15 ? ' ' : '\n'));
}
