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
        getchar(); // ���� \n
        fputc(val, stdout);
        putchar('\n'); //���Ա������ >a, a>
    }

    return  0;
}