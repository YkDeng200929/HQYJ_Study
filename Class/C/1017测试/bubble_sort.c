#include <stdio.h>

void bubble_sort(char *arr, int len)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    char arr[5] = "cabde";
    bubble_sort(arr, 5);
    printf("%s\n", arr);

    return 0;
}