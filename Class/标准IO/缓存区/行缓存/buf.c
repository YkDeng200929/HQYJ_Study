#include <stdio.h>

int main(void)
{
    // 存放至缓存区
    printf("Hello");

    /*
    for (int i = 0;  i <= 1025; i++)
    {// 缓存区满时刷新
        printf("b");
    }
    */
    fflush(stdout);// 强制刷新缓存
    // putchar('\n'); 也可以刷新缓存, 但只限 行缓存

    //while (1); // 
    return 0;
}