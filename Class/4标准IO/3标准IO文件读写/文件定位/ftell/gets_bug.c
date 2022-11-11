#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[8] = {0};

    gets(buf);
    printf("%s\n", buf);

    return 0;
}