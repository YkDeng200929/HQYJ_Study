#include <stdio.h>

int main()
{
    //题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
    int m = 16, n = 32;
    //scanf("%d %d", &m, &n);
    int temp1 = m, temp2 = n;
    int i, j, k=0;
    int max_in=1, min_bei=1;
    int num[100]; // 用于以后计算公因数
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j < 9; j++)
        {
            if (temp1 % j == 0 && temp2 % j == 0)
            {
                num[k++] = j;
                temp1 /= j;
                temp2 /= j;
            }
        }
    }
    num[k] = '\0';
    for (i = 0; num[i] != '\0'; i++)
    {
        max_in *= num[i];
        min_bei *= num[i];
    }
    min_bei *= (temp1*temp2);
    printf("max: %d min: %d\n", max_in, min_bei);
    /*答案
    int a, b, num1, num2, temp;
    printf("Please input to numbers:\n");
    scanf("%d %d", &num1, &num2);
    if (num1 < num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temo;
    }
    a = num1; b = num2;
    while (b != 0)// 利用辗转除法, 直到 b 为 0 为止
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    printf("公约数: %d 公倍数: %d\n", a, num1 * num2 / a);
    */


    return 0;
}