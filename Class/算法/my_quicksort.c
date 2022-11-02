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
        // 右往左遍历
        while (first < last && arr[last] > key)
        {
            last--;
        }
        // 当从右往左遍历时遇到比头还小的, 就退出循环
        // 将当前的小值给前面的头
        arr[first] = arr[last];

        // 左往右遍历
        while (first < last && arr[first] < key)
        {
            first++;
        }
        // 当遇到比尾还大的数, 就退出循环
        // 尾值替换为目前值, 也就是头值
        arr[last] = arr[first];
    }

    // 一轮循环结束
    arr[first] = key;
    quicksort(arr, low, first-1);
    quicksort(arr, first+1, high);
}

int main(void)
{
    int arr[] = {10,44,23,25,27,99,63,21};

    return 0;
}