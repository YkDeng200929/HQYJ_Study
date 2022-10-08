/*1.打印九九乘法表（结果要三角形的九九乘法表）
2.打印出所有的“水仙花”数。所谓“水仙花”数是指一个3位数，其各个位数字立方和等于该数本身。
（编程题要注意代码规范，基本的代码规范：1.运算符前后要加空格，2.一条语句要放在一行，花括号同样单独放一行；3.代码要进行缩进对齐，可以在命令行模式下按gg=G来让代码自动对齐。）*/

#include <stdio.h>
void nine_chart(void)
{
    for (int i = 1; i <=9; i++)
    {
        for (int b = 1; b<=i; b++)
        {
            printf("%d x %d = %d", i, b, i*b);
        }
        printf("\n");
    }
}

int get_h(int num)
{
    int res = num/100;
    return 0;
}

int get_s(int num2)
{
    int res = num2%100/10;
    return res;
}

int get_g(int num3)
{
    int res = num3%10;
    return res;
}

int for_three(int number)
{
    int res = number*number*number;
    return res;
}
void print_flower(void)
{
    for (int i=100; i<=999; i++)
    {
        if (i==(for_three(get_h())+for_three(get_s(i))+for_three(get_g(i))))
        {
            printf("%d ", i);
        }
    }
}

int main(void)
{
    nine_chart();
    print_flower();

    return 0;
}