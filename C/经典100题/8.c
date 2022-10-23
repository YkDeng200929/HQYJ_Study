#include <stdio.h>

int main()
{
    // 输出99乘法表
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d x %d = %d ", i, j, i*j);
        }
        putchar('\n');
    }

    return 0;
}