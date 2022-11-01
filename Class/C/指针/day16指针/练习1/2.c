#include <stdio.h>

int main()
{
    int a[5];
    int n;
    int sum;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("enter: ");
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < sizeof(a)/sizeof(a[0]); j++)
    {
        if (a[j] >= 0)
        {
            sum += a[j];
        }
    }
    printf("sum: %d\n", sum);

    return 0;
}