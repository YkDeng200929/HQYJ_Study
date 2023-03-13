#include <stdio.h>

int main()
{
    //题目：用*号输出字母c的图案。
    int i, j; // 用于控制行列
    for (i = 0; i <= 5; i++)
    {
        for (j = 0; j <= 5; j++)
        {
            if (i == 0 || i == 5 )
            {
                printf("*");
            }
            else if (j == 1 || j == 2)
            {
                printf("*");
            }
        }
        putchar('\n');
    }

    return 0;
}