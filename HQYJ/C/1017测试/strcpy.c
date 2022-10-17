#include <stdio.h>

char *my_strcpy(char *strDest, const char *strSrc)
{
    int i, j = 0;
    for (i = 0;strSrc[i] != '\0'; i++)
    {
        strDest[j++] = strSrc[i];
    }
    strDest[j] = '\0';

    return strDest;
}

int main()
{
    char arr1[] = "hello";
    char arr2[] = "world";
    printf("before:%s %s", arr1, arr2);
    my_strcpy(arr1, arr2);
    printf("now:%s %s", arr1, arr2);

    return 0;
}