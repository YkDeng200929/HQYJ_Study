#include <stdio.h>

int calc_data(int a, int b, int *c)
{
    int res;
    if (a < b)
        res = b;
    else
        res = a;
    (*c) = a + b;
    return res;
}

int main()
{
    printf("这是练习1\n");
    int a,b,max_value,sum;
    printf("Enter:\n");
    scanf("%d %d", &a, &b);
    max_value=calc_data(a,b,&sum);
    printf("a = %d b = %d max = %d sum = %d\n", a, b, max_value,sum);
    
    return 0;
}