#include <stdio.h>

int main()
{
    // 虽然 arr 是数组首元素地址 但是 arr 和 &arr 还是有区别的
    int arr[5] = {1,2,3,4,5};
    int *point = arr; // 定义一个指针变量指向数组
    int (*point2)[5];
    //point2 = arr;      通过数组指针访问数组，因为此时 *point2 指向数组arr，所以 *point2 应表示为 &arr;
    point2 = &arr;
    int i;
    for (i = 0; i < 5; i++)
    {
        // 通过指针变量访问数组
        // printf("%d ", *(point + i));

        // 通过数组指针访问元素
        printf("%d ", *(*point2 + i));// 因为 *point2 为地址， 所以需要再加上一个 * 来调用 arr 数组的元素
    }
    putchar('\n');

    return 0;
}