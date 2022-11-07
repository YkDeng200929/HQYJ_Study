#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fun1(void)
{
    printf("Hello1\n");
}

void fun2(void)
{
    printf("hello2\n");
    //exit(0);// 会刷新缓冲区
    // 系统调用没有缓存, 所以无法将以上两句打印出来
    _exit(EXIT_SUCCESS);// 不会刷新缓冲区
}

int main(void)
{
    fun1();
    fun2();

    return 0;
}
