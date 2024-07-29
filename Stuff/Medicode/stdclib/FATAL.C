/* Exit program with an error message */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void fatal(char *fmt, ...)
{
    va_list args;

    if (strlen(fmt) > 0)
    {
        va_start(args,fmt);
        vfprintf(stderr,fmt,args);
        va_end(args);
    }
    exit(1);
}
