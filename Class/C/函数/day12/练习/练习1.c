#include <stdio.h>

int do_sum(int m)
{
    int i, ret = 0;
    if (m%2 == 0)
    {
        for (i = 0; i <= m; i+=2)
            ret += i;       
    }
    else
    {
        for (i = 1; i <= m; i+=2)
            ret += i;       
    }

    return ret;
}

int main()
{
    int m;
    printf("Enter:\n");
    scanf("%d", &m);
    printf("ret:%d\n",do_sum(m));

    return 0;
}