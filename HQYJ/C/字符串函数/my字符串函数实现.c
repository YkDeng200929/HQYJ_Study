#include <stdio.h>
#include <string.h>

char my_strcat(char *a, char *b)
{
    int i = 0, j = 0;
    while (*(a+i))
    {
        i++;
    }
    while (*(b+j))
    {
        a[i++] = b[j++];
    }
    a[i] = '\0';
}

char my_strcpy(char *a, char *b)
{
    int i, j = 0;
    for (i = 0; b[i] != '\0'; i++)
    {
        a[j++] = b[i];
    }
    a[j] = '\0';
}

int my_strcmp(char *a, char *b)
{
    // strcmp 逐个比较, 直到判断到两个字符不相同时返回ASCII相减值
    int i = 0, j = 0, ret = 0;
    // 当判断到 '\0' 时退出
    while (a[i] == b[j] && a[i] != '\0' && b[j] != '\0')
    {
        i++; j++;
    }
    ret = a[i] - b[j];
}

int my_strlen(char *a)
{
    int count = 0;
    while (*a++)
    {
        count++;
    }
    return count;
}

int main()
{
    char a[] = "hello";
    char b[] = "world";
    printf("a: %s, b: %s\n", a, b);
    my_strcpy(a, b);
    printf("a: %s, b: %s\n", a, b);
    my_strcat(a, b);
    printf("a: %s, b: %s\n", a, b);
    printf("%d\n", my_strcmp(a, b));
    printf("%d\n", strcmp(a, b));
    char c[] = "hdiwfh";
    char d[] = "wieieieiieieie";
    printf("c: %s, d: %s\n", c, d);
    my_strcat(c, d);
    printf("c: %s, d: %s\n", c, d);
    my_strcpy(c, d);
    printf("c: %s, d: %s\n", c, d);
    printf("%d\n", my_strcmp(c, d));
    printf("%d\n", strcmp(c, d));
    char e[] = "apple";
    char f[] = "cat";
    printf("%d\n", my_strcmp(e,f));
    printf("%d\n", strcmp(e,f));
    printf("%d\n", my_strlen(e));

    return 0;
}