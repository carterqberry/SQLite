/* tmath.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t start, stop;
    struct tm *now;
    int ndays;

    /* Get current date and time */
    time(&start);
    now = localtime(&start);

    /* Enter an interval in days */
    fputs("How many days from now? ",stderr);
    if (scanf("%d",&ndays) != 1)
        return EXIT_FAILURE;
    now->tm_mday += ndays;
    if (mktime(now) != -1)
        printf("New date: %s",asctime(now));
    else
        puts("Sorry. Can't encode your date.");
    
    /* Calculate elapsed time */
    time(&stop);
    printf("Elapsed program time in seconds: %f\n",
           difftime(stop,start));

    return EXIT_SUCCESS;
}

/* Output:
New date: Sat Oct 30 18:18:13 1999
Elapsed program time in seconds: 3.000000
*/

