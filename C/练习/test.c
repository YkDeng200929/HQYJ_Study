#include <stdio.h>

int main(void)
{
    int num1;
    static int num2;

    unsigned int a = 0x20;
    a = a >> 2;
    a = ~a;

    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("%d\n", a);

    return 0;
}