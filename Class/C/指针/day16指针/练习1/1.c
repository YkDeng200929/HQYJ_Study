#include <stdio.h>

int main()
{
    int a[6] = {1,2,3,4,5,6};
    int max = a[0];
    int n;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            n = i;
        }
    }
    printf("max: %d n: %d\n", max, n);

    return 0;
}