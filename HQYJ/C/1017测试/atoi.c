#include <stdio.h>

// 将字符串 123456 变成 int 类型整数
// 思路：'9' - '0' 就相当于 整数 9
int atoi(char *strings)
{
    char *p = strings;
    char c;
    int i = 0;
    // 把123456 遍历一遍
    while (c = *p++)
    {
        if (c >= '0' && c <= '9')
        {
            // 当前 字符 - '0' 的差值 就是该数的大小
            i = i*10 + (c-'0');
        }
        else
            return -1;
    }
    return i;
}

int main()
{
    printf("%d\n", atoi("123456"));

    return 0;
}