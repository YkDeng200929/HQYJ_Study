#include <stdio.h>

int main()
{
    char a1[] = "abcde";
    char a2[] = "HELLO";

    char *p_array[] = {a1, a2, NULL};

// 一级指针取 p_array 元素, 二级指针取每个元素的具体值
    int i=0;
    // i++ 不能置于 while 判断中, 否则会出现段错误
    while (p_array[i])
    {
        //printf("%c\n", p_array[i][2]);
        int j = 0;
        for (j; j < 5; j++)
        {
            // 语法糖， 将 p_array 理解成一个二维数组
            if (p_array[i][j] > 'Z')
            {
            // 因为 ASCII 码中字母排序 是 A-Z a-z, 所以以 Z 为分界点
                p_array[i][j] -= 32;
            }
            else
                p_array[i][j] += 32;
        }
        i++;
    }
    /* 另解 
    for (i = 0; p_array[i] != NULL; i++)
    {
        // 将 p 理解成 p_array 每一个元素, 也就是字符串的地址 
        for (p = p_array[i]; *p != '\0'; p++)
        {
            if (*p >= 'A' && *p <= 'Z')
            {
                *p = *p + 32;
            }
            else if (*p >= 'a' && *p <= 'z')
            {
                *p = *p - 32;
            }
        }
    }
    
    */
    printf("%s %s\n", a1, a2);


    return 0;
}