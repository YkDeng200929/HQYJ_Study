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

int arrange(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            int temp;
            if (a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return 1;
}

int print_arr(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 1;
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
    cal(a, arrange, 5);
    cal(a, print_arr, 5);

    return 0;
}