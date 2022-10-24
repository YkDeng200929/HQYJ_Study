#include <stdio.h>

void arrange(int *arr, int len)
{
    int i, j ;
    // 冒泡排序实现倒序
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - i - 1; j++)
        {
            int temp;
            if (arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_arr(int *arr, int len)
{
    int i;
    for (i = 0; i < len ;i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

// 交换两个变量值
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void design(int n)
{
    int i, ret = 0;
    if (n%2 == 0)
    {
        for (i = 0; i <= n; i++)
        {
            if (i%2 == 0)
                ret += i;
        }
    }
    else
    {
        for (i = 0; i <= n; i++)
        {
            if (i%2 != 0)
                ret += i;
        }
    }
    printf("%d\n", ret);
}

int main()
{
    int arr[5] = {4,5,3,1,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, len);
    arrange(arr, len);
    print_arr(arr, len);

    int a = 2, b = 3;
    printf("Before:a: %d b:%d\n", a, b);
    swap(&a, &b);
    printf("After:a: %d b:%d\n", a, b);

    int c;
    printf("Enter:\n");
    scanf("%d", &c);
    design(c);

    return 0;
}