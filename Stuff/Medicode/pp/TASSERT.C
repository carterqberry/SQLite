/* tassert.c:   Force an assertion failre */
#include <stdio.h>
#include "assert.h"     /* From current directory */

main()
{
    int i = 0;

    assert(i > 0);
    return 0;
}
