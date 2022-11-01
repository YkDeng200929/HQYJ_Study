#include <stdio.h>

void swap(int *min, int *now)
{
    int temp;
    temp = *min;
    *min = *now;
    *now = temp;
}

void select_sort(int *arr, int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        int min_index = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(&arr[min_index], &arr[i]);
    }
}

void print_arr(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

int main()
{
    int arr[5] = {5,3,2,1,6};
    print_arr(arr, 5);
    select_sort(arr, 5);
    print_arr(arr, 5);

    return 0;
}