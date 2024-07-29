#include <stdio.h>
#include <stdarg.h>

int maxn(size_t,...);

int main()
{
    printf("max = %d\n",maxn(3,1,3,2));
    return 0;
}

int maxn(size_t count, ...)
{
    int n, big;
    va_list numbers;

    va_start(numbers,count);

    big = va_arg(numbers,int);
    while (--count)
    {
        n = va_arg(numbers,int);
        if (n > big)
            big = n;
    }

    va_end(numbers);
    return big;
}

