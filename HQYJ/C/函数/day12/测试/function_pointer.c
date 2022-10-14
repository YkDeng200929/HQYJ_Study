#include <stdio.h>

int sum(int x, int y)
{
    return x+y;
}

int main()
{
    int (*add)(), x=10, y=20;
    add  = sum;  
    int (*add2)();
    add2 = &sum;
    printf("%d\n", add(x,y));
    printf("%d\n", add2(x,y));
    printf("%d\n", (*add2)(x,y));

    return 0;
}