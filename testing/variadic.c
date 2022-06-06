#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...)
{
    int s = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        s += va_arg(args, int);
    }
    va_end(args);

    return s;
}

int main()
{
    int s = sum(5, 10, 20, 30, 40, 50);
    printf("Sum = %d\n", s);
}