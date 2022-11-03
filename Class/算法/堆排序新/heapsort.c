#include <stdio.h>

void swap(int tree[], int i, int j)
{
    int temp;
    temp = tree[i];
    tree[i] = tree[j];
    tree[j] = temp;
}

// ����С�� (���ڸ�������󶥶�)
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

// �����󶥶�
void build_heap(int tree[], int n)
{
    // ���һ���ڵ�ĸ��ڵ㿪ʼ, ���εݼ��� 0 , �����ж�ÿ�����ڵ���й���С��
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;
    int i = 0;
    for (i = parent; i >= 0; i--)
    {
        heapify(tree, n, i);
    }


}

// ����С����
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
    // ����һ��С��
    printf("ԭʼ:\n");
    print_arr(arr, len);
    printf("����С�Ѻ�:\n");
    heapify(arr, len, 0);
    print_arr(arr, len);
    printf("�����󶥶Ѻ�:\n");
    build_heap(arr, len);
    print_arr(arr, len);

    return 0;
}