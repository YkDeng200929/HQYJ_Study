#include <stdio.h>
#include <math.h>

int main(void)
{
/*
题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
*/

// 完全平方数: 某个数 等于另一个整数的平方, 则该数称完全平方数

    long int num, temp_num1, temp_num2;
    int count = 0;
    // sqrt 用于开平方根
    for (num = 1; num < 100000; num++)
    {
        temp_num1 = sqrt(num + 100);
        temp_num2 = sqrt(num + 268);
        if ((num + 100 == temp_num1 * temp_num1) && (num + 268 == temp_num2 * temp_num2))
            count++;
    }
    printf("%d\n", count);

    return 0;
}
