#include <stdio.h>
int mystrcmp(const char *source, const char *str)
{
    if (source == NULL && str == NULL)
        return 0;
    int len = 0;
    for (; *source != '\0' && *str != '\0'; ++source, ++str)// 两个字符串都没有结束
    {
        if (*source != *str)// 两个字符串内容不相同
            return 0;// 返回0
        ++len;
    }
    if (*str != '\0') // 子字符串未遍历结束
        return 0;
    return len;// 两个字符串相等，返回相等长度
}

// 删除str 中 substr 部分

int del_substr(char *str, const char *substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    int len = 0;
    for (; *str != '\0'; ++str) // 遍历 str 字符串
    {
        if (!len)
        {
            len = mystrcmp(str, substr);
        }
        else
        {
            *(str - 1) = *(str +len - 1); // 将相同部分之后的元素复制到前面
        }
    }
    if (len) // 返回长度，则删除成功
    {
        return 1;
    }
    return 0;
}

int main()
{
    return 0;
}