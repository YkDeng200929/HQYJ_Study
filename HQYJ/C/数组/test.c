#include <stdio.h>

void printarr(int *arr[][3])
{
    for (int i =0; i < 3; i++)
    {
        for (int b=0; b<3; b++)
            printf("%d", arr[i][b]);
        printf("\n");
    }
}
void fun(int num, int arr[][3])
{
    int a = 0;
    for (a; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            for(int c=0; c<b; c++)
            {
                arr[a][c] *= num;
            }
        }
    }
    
}

int main()
{
    int arr[3][3] = {0,1,2,3,4,5,6,7,8,9,10};
    printarr(arr);
    fun(3,arr);
    printarr(arr);

    return 0;
}


/*
void printarr(int arr[][2])// 二维数组作为函数参数的方式
{
    
    for (int i=0; i<2; i++)
    {
        for (int b=0; b<2; b++)
        {
            printf("%d", arr[i][b]);
        }
        printf("\n");
    }

}

int main()
{
    int arr[2][2] = {0,1,2,3};
    printarr(arr);
    //int **arr2;
    

    return 0;
}
*/