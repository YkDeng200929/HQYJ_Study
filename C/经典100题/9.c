#include <stdio.h>

int main()
{
    // 输出国际象棋棋盘
    // 8x8
    
    int i, j; // 控制行列
    char black = 219;
    for (i = 1; i <= 8; i++)
    {
        for (j = 1; j <= 8; j++)
        {
            if (i % 2 == 0)// 基数先输出黑格
            {
                if (j % 2 == 1)
                {
                    printf("%c", black);
                }
                else
                    printf(" ");
            }
            else
            {
                if (j % 2 == 0)
                    printf("%c",  black);
                else
                    printf(" ");
            }
        }
        putchar('\n');
    }
    
    /*解析
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // 行列之和为 偶数 则输出黑方格
            if ((i+j)%2 == 0)
                printf("%c%c", 219, 219);
            else
                printf(" ");
        }
        printf("\n");
    }
*/

    return 0;
}