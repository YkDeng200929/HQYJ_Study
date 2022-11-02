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
        // ���������
        while (first < last && arr[last] > key)
        {
            last--;
        }
        // �������������ʱ������ͷ��С��, ���˳�ѭ��
        // ����ǰ��Сֵ��ǰ���ͷ
        arr[first] = arr[last];

        // �����ұ���
        while (first < last && arr[first] < key)
        {
            first++;
        }
        // ��������β�������, ���˳�ѭ��
        // βֵ�滻ΪĿǰֵ, Ҳ����ͷֵ
        arr[last] = arr[first];
    }

    // һ��ѭ������
    arr[first] = key;
    quicksort(arr, low, first-1);
    quicksort(arr, first+1, high);
}

int main(void)
{
    int arr[] = {10,44,23,25,27,99,63,21};

    return 0;
}