#include <stdio.h>

int *sum(int x, int y)
{
    static int ret;// 因为 ret 在函数调用完成后被释放，所以需要定义为局部静态变量
    ret = x + y;
    return &ret;   
}

int main()
{
    int a=10, b=20;
    int *p = sum(a,b);
    printf("%d\n", *p);

    return 0;
}