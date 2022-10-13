#include <stdio.h>

void printarr(int (*a)[3], int len_i, int len_j) //(*a)[3] == a[][3]
{
    for (int i = 0; i < len_i; i++)
    {
        for (int j = 0; j < len_j; j++)
        {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}
/*
    将二维数组右上角三角形乘以num
*/
void triangle(int (*a)[3], int len_i, int len_j, int num)
{
    int i,j;
    for (i=0;i<len_i;i++)
    {
        for (j=i;j<len_j;j++)
        {
            a[i][j] *= num;
        }
    }
}


int main(void)
{
    //int j=3;
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printf("前\n");
    printarr(arr,3,3);
    //triangle(arr,3);
    triangle(arr,3,3,3);
    printf("后\n");
    printarr(arr,3,3);
    

    return 0;
}