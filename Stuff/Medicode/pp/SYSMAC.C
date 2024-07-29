/* sysmac.c:    Print system macros */

#include <stdio.h>

main()
{
    printf("__DATE__ == %s\n",__DATE__);
    printf("__FILE__ == %s\n",__FILE__);
    printf("__LINE__ == %d\n",__LINE__);
    printf("__TIME__ == %s\n",__TIME__);
    return 0;
}

/* Output:
__DATE__ == Jul 21 1999
__FILE__ == SYSMAC.C
__LINE__ == 9
__TIME__ == 15:28:53
*/

