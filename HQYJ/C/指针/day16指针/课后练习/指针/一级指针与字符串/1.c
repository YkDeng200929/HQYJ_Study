#include <stdio.h>

int main()
{
    char *string1 = "1a2b3C4D";
    char buf[100];
    // 遍历字符串
    int i, j = 0;
    char alpha = 'a';
    char Alpha = 'A';
    for (i = 0; i < sizeof(string1)/sizeof(string1[0]); i++)
    {
        // 判断是否有字母
        for (; alpha <= 'z'; alpha++)
        {
            if (string1[i] == alpha)
                buf[j++] = alpha;
        }
        for (; Alpha <= 'Z'; Alpha++)
        {
            if (string1[i] == Alpha)
                buf[j++] = Alpha;
        }
    }
    buf[j] = '\0';
    printf("%s\n", buf);

    return 0;
}