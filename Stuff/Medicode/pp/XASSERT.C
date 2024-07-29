#include <stdio.h>
#include <stdlib.h>

void __assert(char *cond, char *fname, long lineno)
{
    fprintf(stderr,"Assertion failed: %s, file %s, line %ld\n",
            cond,fname,lineno);
    abort();
}
