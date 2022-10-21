#include <stdio.h>
#include <string.h>
strcmp()

int main()
{
    char buf[] = "i love china";
    int len = sizeof(buf)/sizeof(buf[0]);
    int i, j = len - 2;
    char temp;
    for (i = 0; i < len/2; i++)
    {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
        j--;
    }
    printf("%s\n", buf);

    return 0;
}