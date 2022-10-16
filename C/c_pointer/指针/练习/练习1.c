#include <stdio.h>

const char *find_char(const char *source, const char *chars)
{
    // source 和 chars 接受的是字符串地址的值， 对 main 中源字符串的值没影响, 所以能对 source 进行变化，而 *source 不能被改变， *source 是源字符串
    // 指针为空或字符串为空字符串
    if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
        return NULL;
    for (; *source != '\0'; ++source)        // 遍历源字符串
    {
        for  (; *chars != '\0'; ++chars)     // 遍历给定的字符串
        {
            if (*source == *chars)          // 存在匹配字符
                return source;              // 返回指定源字符串中这个字符的指针
        }
    }
    return NULL;
}

int main()
{
    printf("%c\n",*find_char("hello", "love"));

    return 0;
}