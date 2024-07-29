/* trace2.c: Illustrate a trace macro for debugging */

#include <stdio.h>

#define trace(x,format) printf(#x " = %" #format "\n",x)
#define trace2(i) trace(x ## i,d)
#define x1 SURPRISE!

main()
{
    int x1 = 1, x2 = 2, x3 = 3;
    trace2(1);
    trace2(2);
    trace2(3);
    return 0;
}

