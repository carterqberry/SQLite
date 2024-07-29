/* tformat.c: Various formats of date and time */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t tval;
    struct tm *now;
    char buf[BUFSIZ];
    char *fancy_format =
        "Or getting really fancy:\n"
        "%A, %B %d, day %j of %Y.\n"
        "The time is %I:%M %p.";

    /* Get current date and time */
    tval = time(NULL);
    now = localtime(&tval);
    printf("The current date and time:\n"
           "%d/%02d/%02d %d:%02d:%02d\n\n",
           now->tm_mon+1, now->tm_mday, now->tm_year,
           now->tm_hour, now->tm_min, now->tm_sec);
    printf("Or in default system format:\n%s\n",
           ctime(&tval));
    strftime(buf,sizeof buf,fancy_format,now);
    puts(buf);

    return EXIT_SUCCESS;
}

/*  Output
The current date and time:
7/22/99 18:15:29

Or in default system format:
Thu Jul 22 18:15:29 1999

Or getting really fancy:
Thursday, July 22, day 203 of 1999.
The time is 06:15 PM.
*/

