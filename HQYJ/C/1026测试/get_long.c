#include <stdio.h>

int main()
{
    char str[] = "jdwioij joje iioj iqwiowfjew iwqeiw jdwjoiwejfiowejfjkefjkkff";
    char buf[100];

    int max_count = 0, max_index = 0, max = 0, i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            max_count++;
        }
        else
        {
            if (max_count > max)
            {
                max = max_count;
                max_index = i-1;
                max_count = 0;
            }
        }
        i++;
    }
    // 避免最后一个字符串最长
    if (max_count > max)
    {
        max = max_count;
        max_index = i-1;
        max_count = 0;
    }
    //printf("%c\n", str[max_index]);
    while (str[max_index] != ' ')
    {
        max_index--;
    }
    max_index++;
    while (str[max_index] != ' ' && str[max_index] != '\0')
    {
        buf[j++] = str[max_index];
        max_index++;
    }
    buf[j] = '\0';
    printf("%s\n", buf);

    return 0;
}