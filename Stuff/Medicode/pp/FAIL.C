/* fail.c:   Force an assertion failre */
#include <stdio.h>
#include <assert.h>

main()
{
    int i = 0;

    assert(i > 0);
    return 0;
}
