#include <stdio.h>
typedef int (*Func_point)();

int sum(int x, int y)
{
    return x+y;
}

int main()
{
    Func_point p = sum;
    printf("%d\n", p(1,2));

    return 0;
}