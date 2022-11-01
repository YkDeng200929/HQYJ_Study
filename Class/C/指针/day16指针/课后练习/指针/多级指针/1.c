#include <stdio.h>

int main()
{
    char a[] = "hello";
    char *p = &a[0];
    char **q = &p;
    // 1、要求通过 p 输出数组中每个字符和其对应的 ASCII 码
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        printf("In p: ");
        printf("%c %d\n", *(p+i), (int)*(p+i));
    // 2、要求通过 q 输出数组中对应的每一个字符与其对应的 ASCII 码
        printf("In q: ");
        printf("%c  %d\n", *(*q + i), (int)*(*q + i));
    }

    return 0;
}