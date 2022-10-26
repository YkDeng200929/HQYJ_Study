#include <stdio.h>

int main()
{
    char str[] = "weojfeo jow     e  f oek     o";
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
    printf("%s\n", str);
}