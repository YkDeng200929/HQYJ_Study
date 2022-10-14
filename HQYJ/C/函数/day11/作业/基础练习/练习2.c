#include <stdio.h>

void reverse_data(int *arr)
{
    int i, j;
    for (i = 0; i < 5/2; i++)// 数组第一个元素与最后一个元素换位，之所以为5/2是因为每次交换两个元素位置直至中间位置
    {
        int temp;
        temp = arr[5-1-i];
        arr[5-1-i] = arr[i];
        arr[i] = temp;
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