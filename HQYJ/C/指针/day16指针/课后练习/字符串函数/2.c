// 使用strcmp设计一个程序输入字符串只有当出现"quit"时退出, 否则继续输入
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    do
    {
        scanf("%s", a);
    }while (strcmp(a, "quit"));
    // 当两个字符串相等时, 两个字符串的 ASCII 码值相差为0

    return 0;
}