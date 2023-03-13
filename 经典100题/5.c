#include <stdio.h>

int main()
{
    //题目：输入三个整数x,y,z，请把这三个数由小到大输出。
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int a[] = {x, y, z};
    int i, j;
    // 冒泡排序进行大小的排序
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3 - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for (i = 0; i < 3; i++)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}