// const 的含义就是常量
// const int *p         p 可变, *p 不可变
// int const *p         p 可变, *p 不可变
// int *const p         p 不可变, *p 可变
// const int * const p  p 不可变, *p 不可变

// 常量指针与指针常量
// 1、常量指针: const int *p(这个指针是常量)    常量是指针所指向的值  
// 2、指针常量: int *const p(这个常量是指针)    常量是指针
#include <stdio.h>

int main()
{
    /*例 1
    int data; 
    int * const p = &data;

    data++;
    p++; // 报错, 因为 p 是 const(指针常量)
    (*p)++;
    */

    /*例 2
    int data;
    const int * const p = &data; // 指明都不可变

    data++;
    p++;
    (*p)++;
    */
    // my test
    int p = 30;
    const int *q = &p;
    *(q++);

    return 0;
}