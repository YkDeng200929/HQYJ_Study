#include <stdio.h>

void fun1(void);// 函数第一种定义方式
void fun2(void){
    printf("this is the second function\n");
}               // 函数第二种定义方式

int main(void)
{
    fun1();
    fun2();

    return 0;
}

void fun1(void)
{
    printf("this is first function\n");
}
