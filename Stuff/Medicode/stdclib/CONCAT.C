/* concat.c */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char *concat(char *s,...)
{
    va_list strings;
    char *p;

    /* Copy first string */
    va_start(strings,s);
    if ((p = va_arg(strings,char *)) == NULL)
    {
        *s = '\0';
        return s;
    }
    else
        strcpy(s,p);

    /* Append others */
    while ((p = va_arg(strings,char *)) != NULL)
        strcat(s,p);
    return s;
}

int main()
{
    char buf[128];
    concat(buf,"Sweet","Talker","Betty","Crocker",NULL);
    printf("\"%s\"\n",buf);
    return 0;
}

/* Output:
"SweetTalkerBettyCrocker"
*/

