#include <stdio.h>

int main()
{
    int a[4] = {0, 1, 2, 3};
    //int *p = 0x10001;
    int *p = (int *)0x000000000061FE04;

    printf("%d\n", *p);
    printf("%p\n", &a[1]);
    
    return 0;
}