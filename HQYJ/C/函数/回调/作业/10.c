#include <stdio.h>

int get(int num)
{
    if (num == 0)
        return 1;
    else
        return num * get(num - 1);
}

int main()
{
    printf("%d\n", get(5));

    return 0;
}