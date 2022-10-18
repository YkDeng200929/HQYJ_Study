#include <stdio.h>


int main(void)
{
/*
题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
*/
/*
完全平方数特性：
1、完全平方数的末位数字只能是0, 1, 4, 6, 5, 9

2、对于一个完全平方数:
> 如果他能被 3 整除, 那么他一定能被 9 整除
> 如果他不能被 3 整除, 那么他被 3 除一定余 1

3、两个完全平方数的 积 一定是完全平方数
*/

    int num;
    int judge = num + 100;
    int judge2 = num + 100 + 168;
    for (num = 0; num <= 10; num++)
    {
        if (judge % 3 == 0)
        {
            if (judge % 9 == 0)
            {
                if (judge2 % 3 == 0)
                {
                    if (judge2 % 9 == 0)
                        printf("%d ", num);
                }
                else if (judge2 % 3 == 1)
                    printf("%d ", num);
            }
        }
        else if (judge % 3 == 1)
        {
            if (judge2 % 3 == 0)
            {
                if (judge2 % 9 == 0)
                    printf("%d ", num);
            }
            else if (judge2 %3 == 1)
                printf("%d ", num);
        }
    }

    return 0;
}
