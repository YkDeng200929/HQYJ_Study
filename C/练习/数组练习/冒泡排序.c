#include <stdio.h>

void printarr(int *arr);

int main(void)
{
    int num[5]={2,4,3,1,5};

    printarr(num);

    for (int i =0; i<5; i++)
    {
        for (int b=0; b<5; b++)
        {
            if (num[b] > num[b+1])
            {
                int temp;
                temp = num[b+1];
                num[b+1] = num[b];
                num[b] = temp;
            }
        }
    }

    printarr(num);

    return 0;
}

void printarr(int *arr)
{
    for (int i = 0; i <= 5; i++)
    {
        printf("%d ", arr[i]);
    }
}