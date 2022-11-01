#include <stdio.h>

void sum()
{
    int i = 0;
    int ret = 0;
    for (i = 0; i <= 100; i++)
    {
        ret += i;
    }
    printf("%d\n", ret);
}

int get_three(int i)
{
    return i*i*i;
}

void flower()
{
    int i;
    for (i = 100; i <= 999; i++)
    {
        if (get_three(i/100) + get_three(i%100/10) + get_three(i%10) == i)
            printf("%d\n", i);
    }
}

int main()
{
    return 0;
}