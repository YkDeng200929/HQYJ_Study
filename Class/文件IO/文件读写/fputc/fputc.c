#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    /* my
    int ch;
    while (ch = fgetc(stdin) != EOF)
    {
        fputc(ch, stdout);
    }
    */

    // teacher
    int val;

    while (1)
    {
        putchar('>');
        val = fgetc(stdin);
        if (val == EOF)
        {
            break;
        }
        getchar(); // 吸收 \n
        fputc(val, stdout);
        putchar('\n'); //可以避免出现 >a, a>
    }

    return  0;
}