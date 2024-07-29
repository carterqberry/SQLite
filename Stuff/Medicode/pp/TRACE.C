/* trace.c: Illustrate a trace macro for debugging */
#include <stdio.h>

#define trace(x,fmt) printf(#x " = %" #fmt "\n",x)

int main()
{
    int i = 1;
    float x = 2.0;
    char *s = "three";

    trace(i,d);
    trace(x,f);
    trace(s,s);
    return 0;
}

/* Output:
i = 1
x = 2.000000
s = three
*/

