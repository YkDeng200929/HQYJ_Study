#include <stdio.h>

int main()
{
    int arr[5] = {1,2,3,4,5};

    int *arr2 = &arr[0];
    int i = 1;

    printf("*(arr2+1): %d *(arr2+i): %d\n", *(arr2+1), *(arr2+i));
    for (; arr2 < &arr[5]; )
        *++arr2 = 0;
    for (int j = 0; j < 5; j++)
        printf("%d\n", *(arr+j));
    
    return 0;
}