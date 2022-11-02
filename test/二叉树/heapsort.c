#include <stdio.h>

void heap_sort(int arr[], int len);
void adjust_heap(int arr[], int index, int length);
void swap(int arr[], int a, int b);

int main(void)
{
    int arr[] = {45, 43, 70, 22, 10};
    heap_sort(arr, 5);
    int i;

    return 0;
}

void heap_sort(int arr[], int len)
{
    int i, j;
    for (i = len / 2 - 1; i >= 0; i--)
}