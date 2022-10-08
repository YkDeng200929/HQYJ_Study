#include <stdio.h>

int sum(int num, int num2)
{
    return num+num2;
}

// 指针函数
int* h(int num, int num2) //返回类型为int类型的地址
{
    int arr[2];
    arr[0] = num;
    arr[1] = num2;

    return arr;
}

int main(void)
{
    int (*fun)(int, int);

    fun = sum;// 函数指针相当于定义了另一个变量，这个变量是一个函数
    
    int *arr;
    arr = h(2,1);
    
    printf("%d\n", fun(2,3));
    printf("%d %d\n",arr[0] ,arr[1] );

    return 0;
}