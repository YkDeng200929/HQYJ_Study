#include <stdio.h>

int a[5] = {5, 7, 8, 9, 1};

// 定义 数组 大小
int len = sizeof(a) / sizeof(a[0]);

int i = 0, j = 0;
int temp;

// 以下实现 冒泡排序

void bubble_sort(int *arr)
{
    for (i = 0; i < len - 1; i++)
    {
        // 升序
        if (a[j] > a[j + 1])
        {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }

        // 降序
        if (a[j] < a[j + 1])
        {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}

// 以下实现 简单选择排序
void select_sort(int *arr)
{
    int min = a[i];// 用于寻找最小值
    int max = a[i];// 用于寻找最大值
    int n = i;
    // 寻找 最小(大)值
    for (j = i + 1; j < len; j++)
    {
        // 升序
        if (min > a[j])
        {
            // 更新 最小值 和 最大值 下标
            min = a[j];
            n = j;
        }
        // 降序
        if (max < a[j])
        {
            // 更新 最大值 和  最小值 下标 
            max = a[j];
            n = j;
        }
        // 交换 a[i] 和 未排序中的最 小(大) 值
        if (n != i)
        {
            temp = a[i];
            a[i] = a[n];
            a[n] = temp;
        }
    }

}
int main()
{
    

}