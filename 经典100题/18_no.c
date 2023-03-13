#include <stdio.h>

int get_ten(int num)
{
    int i, ten = 1;
    for (i = 1; i <= num; i++)
    {
        ten *= 10;
    }
}

int main()
{
    /*
    题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时
　　　共有5个数相加)，几个数相加由键盘控制。
    */
    int arr[5][5] = {0};
    int i, j;
    int count_num = 0, result = 0;
    // 先赋值
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            arr[i][j] = 2;
        }
    }
    // 将待计算的数运算成整数
    for (i = 0; i < 5; i++)
    {
        // 每行初始化一次待计算数
        count_num = 0;
        for (j = 0; j < i + 1; j++)
        {
            count_num += (arr[i][j] + arr[i][j]*(get_ten(j)));
        }
        printf("%d x", count_num);
        result += count_num;
    }
    // 打印数组
    /*
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            printf("%d ",arr[i][j]);
        }
        putchar('\n');
    }
    */

    printf("= %d\n", result);

    return 0;
}