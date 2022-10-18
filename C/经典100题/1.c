
/*
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
1.程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后再去
　　　　　　掉不满足条件的排列。*/
#include <stdio.h>

int main()
{
    int i = 1, j = 1, k = 1;
    int num = 0;
    int temp = 0;
    int a;
    // 思路：确保 每位不相同 即可
    for (i = 1; i <= 4; i++)
    {
        // temp = k + 10*j + 100*k; 多余
        for (j = 1; j <= 4; j++)
        {
            for (k = 1; k <= 4; k++)
            {
                // 互不相同且无重复数字!!!!!!!!!!!!!!!
                //num = k + 10*j + 100*i; 多余
                //if (num != temp)
                //    printf("%d ", num);
                // 核心:
                if (i != k && i != j && j != k)
                    printf("%d%d%d ", i, j, k);
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}