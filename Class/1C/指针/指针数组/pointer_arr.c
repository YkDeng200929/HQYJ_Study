#include <stdio.h>
// 数组名是个地址， 而指针是一个左值

int main()
{
    int arr1[5] = {0,1,2,3,4};
    // 定义一个指针数组
    int *arr2[5] = {&arr1[0], &arr1[1], &arr1[2], &arr1[3], &arr1[4]};
    // [] 优先级高于 *， 所以先定义数组 arr2[]， 而每个 arr2[] 都是一个地址
    // 因为每个 arr2[] 都是一个指针， 所以需要 * 来解引用来访问其地址中的值
    int i;
    int (*arr3)[5] = &arr1; // (*arr3)[5] = arr1; 这样会报错，因为 arr1 只是一个名称，而数组指针想要的是一个表示地址的身份

    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(*arr2 + i));
        // arr2 是地址 arr2[] = arr2 + i 又是一个地址
        // 因为身份与名称不同，所以 *arr 才表示 &arr[]
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(*arr2 + i));
        // arr2 是地址 arr2[] = arr2 + i 又是一个地址
    }

    return 0;
}