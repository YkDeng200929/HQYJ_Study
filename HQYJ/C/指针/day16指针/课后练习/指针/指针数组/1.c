#include <stdio.h>

int main()
{
    int a = 10, b = 20, c = 30;
    int *p[] = {&a, &b, &c};
    int i;
    for (i = 0; i < sizeof(p)/sizeof(p[0]); i++)
    {
        printf("%d ", *(*(p+i)));
    }

    return 0;
}