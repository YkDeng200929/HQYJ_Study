#include <stdio.h>

int main()
{
    char buf[100]={0};
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] > 'z')
        {
            buf[i] = buf[i] - 32;
        }
    }
    printf("%s\n", buf);

    return 0;
}