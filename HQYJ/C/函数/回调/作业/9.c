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
    return (x * y )/ 2
}

// �����
int area(int x, int y, int (*function)())
{
    return function(x, y);
}
int main()
{
    return 0;
}