#include <stdio.h>

int main()
{
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printf("arr: %p &arr[0]: %p &arr[0][0]: %p\n", arr, &arr[0], &arr[0][0]);
    printf("arr: %p arr[0]: %d arr[0][0]: %d\n", arr, arr[0], arr[0][0]);
    // arr 相当于二维数组首元素地址(也就是一行一列的元素)

    return 0;
}