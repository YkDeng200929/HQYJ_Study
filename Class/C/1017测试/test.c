#include <stdio.h>

void print_binary(int num)
{
    int temp = num;
    while (num/2 != 0)
    {
        printf("%d", temp%2);
        temp /= 2;
    }
    printf("%d", temp%2);
    putchar('\n');
}

int main()
{
    int a = 1, b = 3;
    print_binary(a);
    printf("%d\n", a);
    a << 2;
    print_binary(a);
    printf("%d\n", a);

    return 0;
}