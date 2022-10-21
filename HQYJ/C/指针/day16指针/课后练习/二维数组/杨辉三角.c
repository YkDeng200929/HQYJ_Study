#include <stdio.h>

int main()
{
    int i, j;
    int a[10][10];
    for (i = 0; i < 10; i++)
    {
        //a[i][0] = 1; 杨辉三角的三角形尾端也为 1 , 所以还需定义 a[i][i] = 1
        a[i][0] = a[i][i] = 1;
        for (j = 1; j < i; j++) // 第一行忽略掉, 否则 a[i][j] 会获取随机数
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
        a[i][j] = 1;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < i; j++)// 因为只打印三角形, 所以不是 j < 10;
            printf("%d ", a[i][j]);
        putchar('\n');
    }

    return 0;
}