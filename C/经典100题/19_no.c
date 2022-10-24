#include <stdio.h>

int main()
{
    /*
    题目：一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程
　　　找出1000以内的所有完数。
    */
    int num, i, j, k = 0, temp;
    int arr[100]; // 用于存放因子
    for (num = 1; num <= 1000; num++)
    {
        temp = num;
        // 用于判断是否为完数
        for (i = 9; i >= 1; i--)
        {
            for (j = 9; j >= 1; j--)
            {
                if (num%i == 0)
                    arr[k++] = j;
                temp /= j;
            }
        }
        // 遍历arr计算因子和
        arr[k] = '\0';
        int result = 0;
        for (i = 0; arr[i] != '\0'; i++)
        {
            result += arr[i];
        }
        if (result == num)
            printf("%d\n", num);
    }


    return 0;
}