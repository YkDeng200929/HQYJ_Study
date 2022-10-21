#include <stdio.h>

int main()
{
    // 要求交换最大值与最小值在数组中的位置
    // 且不利用其他变量来进行交换
    int a[5] = {1,2,3,4,5};
    int *p_max, *p_min;
    p_max = p_min = a;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (a[i] > *p_max)
        {
            p_max = &a[i];
        }
        if (a[i] < *p_min)
        {
            p_min = &a[i];
        }
    }
    /* 以下利用了 temp 变量
    int temp;
    temp = *p_max;
    *p_max = *p_min;
    *p_min = temp;
    */

   // 以下不利用 其他变量
   *p_max = *p_max + *p_min; // max = 5 + 1 = 6
   *p_min = *p_max - *p_min; // min = max - min = 6 - 1 = 5
   *p_max = *p_max - *p_min; // max = max - min = 6 - 5 = 1

    for (int j = 0; j < 5; j++)
        printf("%d ", a[j]);
    putchar('\n');

    return 0;
}