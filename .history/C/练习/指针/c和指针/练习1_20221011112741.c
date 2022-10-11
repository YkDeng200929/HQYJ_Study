/*
编写函数，进行搜索字符串，查找给定字符集合中出现的字符
    char *find_char(char const *source, char const *chars);
*/

#include <stdio.h>

char *find_char(char const *source, char const *chars)
{
    //char *temp = source;
    //char *temp2 = chars;
    for (int i=0; *(source+i)!='\0';)
    {
        if (*(source+i) == *(chars+i))
        {
            int *temp = 
            return source+i;
        }
        else
        {
            i++;
            continue;
        }
    }
    return NULL;
}

int main()
{
    return 0;
}