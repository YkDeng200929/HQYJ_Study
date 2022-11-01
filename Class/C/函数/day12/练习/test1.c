#include <stdio.h>

void fun(char **p)
{
    ++p;
    printf("%s\n", *p);
}

int main()
{
    char *a[] = {"morning", "Afternoon", "Evening", "Night"};
    fun(a);

    return 0;
}