#include <stdio.h>

int main()
{
    int a, n, count = 1;
    long int sn = 0, tn = 0;
    printf("please input a and n\n");
    scanf("%d,%d", &a, &n);
    printf("a = %d, n = %d\n", a, n);
    // 循环计算相加 n 次
    while (count <= n)
    {
        // 计算被加数
        tn = tn + a; // tn = 0 + 2 = 2          tn = 2 + 20 = 22
        // 计算和
        sn = sn + tn; // sn = 0 + 2 = 2         sn = 2 + 22 = 24
        a = a*10;     // a = 2 * 10 = 20        a = 20 * 10 = 200
        ++count;
    }
    printf("%ld\n", sn);

    return 0;
}