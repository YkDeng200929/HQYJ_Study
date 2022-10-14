#include <stdio.h>

void delete_space(char *buffer)
{
    char buf2[1024];
    int i=0, j=0;
    while (buffer[i] != '\0')
    {
        if (buffe++r[i] == ' ')
        {
            i++;
            continue;            
        }
        else
        {
            buf2[j++] = buffer[i++];
        }
    }
    buf2[j] = '\0';
    printf("%s\n", buf2);
}

int main()
{
    char buf[1024] = "hello world";
    printf("输入: ");
    //scanf("%s", buf);
    printf("%s\n", buf);
    delete_space(buf);
    printf("%s\n", buf);

    return 0;
}