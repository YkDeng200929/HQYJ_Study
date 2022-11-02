#include <stdio.h>

void quicksort(int arr[], int first, int last)
{
    int low = first;
    int high = last;
    //int key = arr[first];
    int key = arr[low];

    if (first >= last)
    return;
    while (low < last)
    {
        while (low < high && arr[high] > key)
        {
            high--;
        }
        //arr[high] = key;
        arr[low] = arr[high];
        while (low < high && arr[low] < key)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = key;
    quicksort(arr, first, low-1);
    quicksort(arr, high+1, last);
}

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(void)
{
    int arr[] = {10, 29, 11, 28, 34, 40, 21};
    print(arr, 7);
    quicksort(arr, 0, 7);
    print(arr, 7);

    return 0;
}