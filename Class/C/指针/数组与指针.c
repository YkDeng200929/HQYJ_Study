#include <stdio.h>

int main()
{
    int arr[3];
    int (*fp)[3];
    fp = &arr; // *fp得是地址所以fp得是地址的地址

    //二维数组与指针
    int a[][3];
    // a[0]等同于一维数组的数组名

    return 0;
}