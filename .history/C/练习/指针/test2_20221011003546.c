#include <stdio.h>

void printarr(int *arr)
{
    for(int i=0; i <= (int)sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int main(void)
{
    int a[3] = {1,2,3};

    printarr(a);
    printf("%d\n", )

    return 0;
}