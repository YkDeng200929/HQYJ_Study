#include <stdio.h>


// 若n为正数，则返回其前n项和，否则返回空
int *fun_sum(int n)
{
    static int sum = 0;
    int *p = &sum;
    int i = 0;
    if (n < 0)
    {
        printf("Error\n");
        return NULL;
    }
    for (i = 0; i <= n; i++)
    {
        sum += i;
    }
    return p;
}

int main()
{
    int num = 0;
    int *ret = NULL;
    printf("Please input data:");
    scanf("%d", &num);
    ret = fun_sum(num); 
    printf("%d\n", *ret);
    return 0;
}