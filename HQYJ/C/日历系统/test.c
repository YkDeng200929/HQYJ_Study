#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4};
    for (int i=0; arr[i] != '\0'; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("hello%d\n",printf("hello\n"));
    printf("%+17s", "hello\n");

    return 0;
}