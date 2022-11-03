#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    int max = i;
    if (i >= n)
    return ;
    if (max != n && arr[lchild] > arr[max])
    {
        swap(&arr[lchild], &arr[max]);
        heapify(arr, n, lchild);
    }
    if (max != n && arr[rchild] > arr[max])
    {
        swap(&arr[rchild], &arr[max]);
        heapify(arr, n, rchild);
    }
}

void build_heap(int arr, int n, int i)
{

    int parent = (i - 1) / 2;
    //int lchild = parent * 2 + 1;
    //int rchild = parent * 2 + 2;
    if (i <= 0)
    return ;
    if (parent >= 0)
    {
        heapify(arr, n, parent);
    }
}

int main(void)
{
    int arr[] = {3, 4, 2, 5, 1};
    heapify(arr, 5, 0);
    build_heap(arr, 5, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}