#include <stdio.h>

char * a(void)
{
    static char b[] = "hello";
    return b;
}

int main()
{
    printf("%s\n", a());
    return 0;
}