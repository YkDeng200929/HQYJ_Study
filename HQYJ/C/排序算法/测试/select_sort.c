#include <stdio.h>
void swap(int *min, int *now)
{
    int temp;
    // 逆序
    temp = *min;
    *min = *now;
    *now = temp;
}

void select_sort(int *arr, int len)
{
    int i, j;
    for (i = 0; i < len-1; i++)
    {
        int min_index = i;// 每次假定 每次大循环的 首元素 为最小值
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_index]) // 如果寻找到当前 元素 比 当前最小值更小
            {
                min_index = j; // 此时已将 最小值 替换为 寻找到元素 的 角标
            }
            swap(&arr[min_index], &arr[i]);
        }
    }
}

void bubble_sort(int *arr, int len)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j+1] < arr[j])
            {
                int temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int array[5] = {2,3,1,5,4};
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
    select_sort(array, 5);
//    bubble_sort(array, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');

    return 0;
}