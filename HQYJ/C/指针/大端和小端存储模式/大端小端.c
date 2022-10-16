#include <stdio.h>

int main()
{
    int a[4] = {1,2,3,4};
    int *ptr1 = (int *)(&a + 1);
    // ptr1 是一个地址 指向 2 的地址
    int *ptr2 = (int *)((int)a + 1);
    printf("%x, %x\n", ptr1[-1], *ptr2);

    return 0;
}