#include <stdio.h>

int find_max(int a, int b)
{
    int max;
    max = a > b ? a : b;

    return max;
}

int test(int m)
{
    int ret = 0;
    if (m % 2 == 0)
    {
        for (int i = 0; i <= m; i++)
        {
            if (i%2 == 0)
                ret += i;       
        }
    }
    else
    {
        for (int i = 0; i <= m; i++)
        {
            if (i%2 != 0)
                ret += i;
        }
    }
    return ret;
}

int main()
{
    return 0;
}