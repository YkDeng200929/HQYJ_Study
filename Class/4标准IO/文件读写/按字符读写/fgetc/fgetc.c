#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    int val;
    FILE *fp;
    val = fgetc(stdin);
    printf("%d\n", val);

    return  0;
}