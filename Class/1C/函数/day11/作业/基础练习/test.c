#include <stdio.h>

int main()
{
    int num[4] = {1,2,3,4};

    int i=0;
    while (*(num+i+1) != '\0')
    {
        printf("%d ", *(num+i));
        i++;
    }

    return 0;
}