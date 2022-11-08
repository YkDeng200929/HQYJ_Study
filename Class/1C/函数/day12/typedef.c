#include <stdio.h>
typedef int (*Func_point)();
typedef int ZS;

int sum(int x, int y)
{
    return x+y;
}

int main()
{
    Func_point p = sum;
    printf("%d\n", p(1,2));
    ZS a = 1;
    printf("%d\n", a);

    return 0;
}