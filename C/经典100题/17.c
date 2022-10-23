#include <stdio.h>

int main()
{
    //题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
    char strings[100];
    //scanf("%s", strings); scanf 无法识别空格?
    fgets(strings, 100, stdin);// 使用fgets函数即可
    int count_num = 0, count_alpha = 0, count_space = 0, count_other = 0;
    int i;
    for (i = 0; strings[i] != '\0'; i++)
    {
        if ((strings[i] >= 'a' && strings[i] <= 'z') || (strings[i] >= 'A' && strings[i] <= 'Z'))
            count_alpha++;
        else if (strings[i] == ' ')
            count_space++;
        else if (strings[i] >= '0' && strings[i] <= '9')
            count_num++;
        else
            count_other++;
    }
    printf("num: %d, blank: %d, alpha: %d, other: %d\n", count_num, count_space, count_alpha, count_other);

    return 0;
}