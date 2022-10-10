#include <stdio.h>

int sum(int num1, int num2)
{
    return num1, num2;
}

int sumplush(int (*fp)(int, int), int num)
{
    return fp+num;
}

void hello();

int main(void)
{
    hello();
    sumplush(sum(1,2))

    return 0;
}