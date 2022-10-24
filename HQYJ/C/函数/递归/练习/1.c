#include <stdio.h>

// 实现阶乘
int n(int num)
{
    if (num == 0)
        return 1;
    else
    // 找到已知条件, num = 1 时
        return num * n(num - 1);
    // 已知:  num = 1 : 用于退出循
    // 未知: num > 1; num * (num - 1) : 用于递归
}

int main()
{
    printf("%d\n", n(5));

    return 0;
}