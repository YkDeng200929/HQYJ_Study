#include <stdio.h>

int main()
{
    int data1 = 0, data2 = 0;
    int *p;
    int *q;
    p = &data1;
    q = &data2;
    // 从键盘输入两个数赋给 data1, data2
    // 实现两个数的交换
    int temp;
    scanf("%d %d", p, q);
    printf("data1: %d, data2: %d\n", data1, data2);
    temp = *p;
    *p = *q;
    *q = temp;
    printf("data1: %d, data2: %d\n", data1, data2);

    return 0;
}