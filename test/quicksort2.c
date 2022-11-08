#include <stdio.h>

void quicksort(int arr[], int low, int high)
{
    int first = low;
    int last = high;
    int key = arr[first];

    if (low >= high)
    return ;
    while (first < last)
    {
        while (first < last && arr[last] > key)
        {
            last--;
        }
        //arr[last] = arr[first];
        arr[first] = arr[last];
        while (first < last && arr[first] < key)
        {
            first++;
        }
        //arr[first] = arr[last];
        arr[last] = arr[first];
    }
    arr[first] = key;
    quicksort(arr, low, first - 1);
    //quicksort(arr, last + 1, high);
    quicksort(arr, first + 1, high);
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
    int arr[] = {1,4,5,6,3};
    print(arr, 5);
    quicksort(arr, 0, 4);
    print(arr, 5);

    return 0;
}