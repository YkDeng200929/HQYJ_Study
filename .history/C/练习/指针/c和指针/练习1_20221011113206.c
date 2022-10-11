/*
编写函数，进行搜索字符串，查找给定字符集合中出现的字符
    char *find_char(char const *source, char const *chars);
*/

#include <stdio.h>

char *find_char(char const *source, char const *chars)
{
    // 指针为空或字符串为空字符串
    if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
    {
        return NULL
    }
    for (; *source != '\0'; )
}

int main()
{
    return 0;
}