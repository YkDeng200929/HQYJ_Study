#include <stdio.h>
#include <math.h>

int main()
{
    /* 题目：判断101-200之间有多少个素数，并输出所有素数。
       程序分析：判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除，
　　            则表明此数不是素数，反之是素数。*/
    // 素数: 素数又叫质数。素数，指的是“大于1的整数中，只能被1和这个数本身整除的数”

    /*
    在数学上有个规律，对于一个小于n的整数x，若n不能整除x，则n必定不能整数n/x，
    那么带来一个明显的优化就是循环控制语句从2到sqrt(n)即可，因为在判断2的同
    时也判断了n/2，循环到sqrt(n)时，就把2到n-1都判断了，所以要改进for循环中
    的循环控制语句，改为i <= sqrt(n)
    */

   /*常规暴力解法
   int isPrime(int n)
   {
    if (n < 2)
    {
        return 0;// 如果是非正数
    }
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            return 0; // 依次取余, 若除的尽, 则不是素数
        }
    }
   }
   */

  /* 稍微优化
    int isPrime(int n)
    {
        if (n < 2)
        {
            return 0; // 0 和 1 非素数, 直接判断
        }
        for (int i = 2; i < n/2; i++)
        {
            if (n%i == 0)
            {
                return 0; // 依次取余, 若除的尽, 则不是素数
            }
        }
        return 1;
    }
  */

    /*最终优化
    int isPrime(int n)
    {
        if (n < 2)
        {
            return 0;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n%i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    */


    return 0;
}