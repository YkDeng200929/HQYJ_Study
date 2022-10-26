#include <stdio.h>

int main()
{
    char str[] = "xyz123";
    int i = 0;
    while (str[i])
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            if (str[i] >= 'x' && str[i] <= 'z')
            {
                str[i] = str[i] - 23;
            }
            else
                str[i] = str[i] + 3;
        }
        i++;
    }
    printf("%s\n", str);

    return 0;
}