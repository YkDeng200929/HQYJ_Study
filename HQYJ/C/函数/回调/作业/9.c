#include <stdio.h>

// ������
int rectangle(int x, int y)
{
    return x * y;
}

// ������
int quadrate(int x, int y)
{
    return x * y;
}

// ������
int triangle(int x, int y)
{
    return (x * y )/ 2;
}

// �����
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