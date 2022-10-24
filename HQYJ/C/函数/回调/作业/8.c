#include <stdio.h>

void sort(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            int temp;
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int *array_function(void)
{
    static int a[5] = {5,4,3,2,1};
    int len = sizeof(a)/sizeof(a[0]);
    sort(a, len);
    return a;
}

int main()
{
    int *p = NULL;
    p = array_function();
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    putchar('\n');

    return 0;
}