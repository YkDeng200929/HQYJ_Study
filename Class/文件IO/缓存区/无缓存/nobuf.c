#include <stdio.h>
// 标准出错无缓存
int main(void)
{
    fprintf(stderr, "Hello");

    /*
    for (int i = 0;  i <= 1025; i++)
    {// 缓存区满时刷新
        printf("b");
    }
    */
    fflush(stdout);// 强制刷新缓存

    //while (1); // 
    return 0;
}