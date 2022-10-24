#include <stdio.h>

int sum(int *a, int len)
{
    int ret = 0;
    for (int i = 0; i < len; i++)
    {
        ret += a[i];
    }
    return ret;
}

int cal(int *a, int (*p)(), int len)
{
    int ret = 0;
    ret = p(a, len);
    return ret;
}

int main()
{
    int a[5] = {1,2,3,4,5};
    int len = sizeof(a)/sizeof(a[0]);
    printf("%d\n", cal(a, sum, len));

    return 0;
}