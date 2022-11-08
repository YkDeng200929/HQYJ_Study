#include <stdio.h>

void change_value(int *a, int *b)
{
    *a = 10;
    *b = 20;
}

int main()
{
    int a=0, b=0;
    printf("a:%d b:%d\n", a, b);
    change_value(&a, &b);
    printf("a:%d b:%d\n", a, b);

    return 0;
}