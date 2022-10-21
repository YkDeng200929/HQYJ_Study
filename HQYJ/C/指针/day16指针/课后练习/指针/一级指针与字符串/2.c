#include <stdio.h>

int main()
{
    char str[100];
    char *p_max;    // 保存用户输入的最大字符地址
    char *p_min;    // 保存用户输入最小字符的地址
    // 要求用户从键盘输入任意字符串存放到 str 中
    scanf("%s", str);
    // 字符串数组通过 scanf 输入的时候, 会自动在尾端添加 '\0'
    printf("%s\n", str);
    p_max = p_min = str;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > *p_max)
        {
            p_max = &str[i];
        }
        if (str[i] < *p_min)
        {
            p_min = &str[i];
        }
    }
    printf("max: %c min: %c\n", *p_max, *p_min);
    // 以下交换位置 
    *p_max = *p_max + *p_min;
    *p_min = *p_max - *p_min;
    *p_max = *p_max - *p_min;

    printf("%s\n", str);

    return 0;
}