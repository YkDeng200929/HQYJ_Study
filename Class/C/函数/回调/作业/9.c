#include <stdio.h>

// 长方形
int rectangle(int x, int y)
{
    return x * y;
}

// 正方形
int quadrate(int x, int y)
{
    return x * y;
}

// 三角形
int triangle(int x, int y)
{
    return (x * y )/ 2;
}

// 求面积
int area(int x, int y, int (*function)())
{
    return function(x, y);
}
int main()
{
    int x = 5, y = 4;
    printf("%d\n", area(x, y, triangle));

    return 0;
}