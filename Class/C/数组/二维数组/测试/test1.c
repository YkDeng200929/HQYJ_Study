#include <stdio.h>

int main()
{
    int arr[3][2] = {{1,2}, {3,4}, {5,6}};
    printf("%d\n", *(*arr+1));

    return 0;
}