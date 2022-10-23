#include <stdio.h>

int main()
{
    //题目：打印楼梯，同时在楼梯上方打印两个笑脸。
    // ASCII 码中 28 是楼梯 (换页符), 1 是笑脸
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // 列 -1 = 行 表示在楼梯上
            if (j-1 == i)
                printf("^_^");
            if (i == j)
                printf("|__");
            else
                printf("   ");// 因为不像数组, 所以得有空来辅助顶格
            
        }
        printf("\n");
    }

    return 0;
}