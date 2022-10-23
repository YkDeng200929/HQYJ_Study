#include <stdio.h>

// 用于获取立方和
int cubes_sum(int num)
{
    return num*num*num;
}

int main()
{
    /*
    题目：打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方
    和等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3
    的三次方。
    */
    int i;
    for (i = 100; i <= 999; i++)
    {
        if (cubes_sum(i/100)+cubes_sum(i%10)+cubes_sum(i%100/10) == i)
            printf("%d\n", i);      
    }

    return 0;
}