#include <stdio.h>
/*
char *find_char(char const *source, char const *chars)
{
    int i, j = 0;
    char *temp_source = source;
    char *temp_chars = chars;

    for (i = 0; *(temp_source+i) != '\0'; i++)
    {
        if (*(temp_source+i) == NULL)
            return NULL;
        else if (*(temp_source+i) == *(temp_chars+i))
            return temp_source+i;
    }

    return NULL;
}

int main()
{


    return 0;
}
*/


const char *find_char(const char *source, const char *chars)
{
    // 指针为空或字符串为空字符串
    if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
        return NULL;
    for (; *source!= '\0'; ++source)        // 遍历源字符串
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
    return 0;
}