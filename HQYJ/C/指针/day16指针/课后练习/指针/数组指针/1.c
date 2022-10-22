#include <stdio.h>
#define M 2
#define N 3

int main()
{
    int a[M][N] = {1,2,3,4,5,6};
    // 1、要求用户从键盘输入 6 个数据赋值给数组 a
    // 2、要求使用不同的形式输出数组内容
    // 不适用变量输入数组内容：(偏移量)
    // a 行, a[0] 列
    int (*p)[M][N] = &a; // 
    printf("%d",  ***p++);

    return 0;
}