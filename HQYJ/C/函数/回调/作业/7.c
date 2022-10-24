#include <stdio.h>

void print_arr(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

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

int main()
{
    int a[5] = {5,4,3,2,1};
    int len = 5;
    sort(a, len);
    print_arr(a, len);

    return 0;
}