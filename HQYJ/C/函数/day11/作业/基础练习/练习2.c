#include <stdio.h>

void reverse_data(int *arr)
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5-i; j++)
        {
            int temp;

            temp = *(arr+j+1);
            *(arr+j+1) = *(arr+j);
            *(arr+j) = temp;
        }
    }
}

void printarr(int *arr)
{
    int i=0;
    while (*(arr+i) != '\0')
    {
        printf("%d ", *(arr+i));
        i++;
    }
    putchar('\n');
}

int main()
{
    int i, buf[5] = {1,2,3,4,5};
/*
    for (i=0; i<5; i++)
    {
        printf("输入:\n");
        scanf("%d", &buf[i]);
    }
*/
    printarr(buf);
    reverse_data(buf);
    printarr(buf);

    return 0;
}