#include <stdio.h>

int main()
{
    char *string1 = "1a2b3C4D";
    char buf[100];
    // 遍历字符串
    int i, j = 0;
    char alpha;
    char Alpha;
    for (i = 0; i < 8; i++)
    {
        // 判断是否有字母
        for (alpha = 'a'; alpha <= 'z'; alpha++)
        {
            if (string1[i] == alpha)
                buf[j++] = alpha;
        }
        for (Alpha = 'A'; Alpha <= 'Z'; Alpha++)
        {
            if (string1[i] == Alpha)
                buf[j++] = Alpha;
        }
    }
    buf[j] = '\0';
    printf("%s\n", buf);

    return 0;
}