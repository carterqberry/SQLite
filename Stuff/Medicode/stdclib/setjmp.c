#include <stdio.h>
#include <setjmp.h>

jmp_buf recover;

void g(void)
{
    printf("In g()\n");
    longjmp(recover, 5);
}

void f(void)
{
    printf("In f(), calling g()\n");
    g();
    printf("returned from g()\n");
}

int main()
{
    volatile int code = 0;
    if ((code = setjmp(recover)) != 0)
    {
        printf("returned from longjmp: %d\n", code);
    }
    else
        f();
    return 0;
}

/* Output:
In f(), calling g()
In g()
returned from longjmp: 5
*/

