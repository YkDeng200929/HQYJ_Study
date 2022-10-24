#include <stdio.h>

int global_data = 0;

int global_add(void)
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        global_data++;
    }
    return global_data;
}

int main()
{
    printf("%d\n", global_add());

    return 0;
}