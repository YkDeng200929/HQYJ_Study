#include <stdio.h>

void swap(int tree[], int i, int j)
{
    int temp;
    temp = tree[i];
    tree[i] = tree[j];
    tree[j] = temp;
}

// 构建小堆 (用于辅助构造大顶堆)
void heapify(int tree[], int n, int i)
{
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    int max = i;
    if (i >= n)
    return ;
    if (lchild < n && tree[lchild] > tree[max])
    {
        max = lchild;
    }
    if (rchild < n && tree[rchild] > tree[max])
    {
        max = rchild;
    }
    if (max != i)
    {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
}

// 构建大顶堆
void build_heap(int tree[], int n)
{
    // 最后一个节点的父节点开始, 依次递减到 0 , 过程中对每个父节点进行构造小堆
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;
    int i = 0;
    for (i = parent; i >= 0; i--)
    {
        heapify(tree, n, i);
    }


}

// 构建小顶堆
void heap_sort(int tree[], int n)


void print_arr(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}


int main(void)
{
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    // 构建一个小堆
    printf("原始:\n");
    print_arr(arr, len);
    printf("构建小堆后:\n");
    heapify(arr, len, 0);
    print_arr(arr, len);
    printf("构建大顶堆后:\n");
    build_heap(arr, len);
    print_arr(arr, len);

    return 0;
}