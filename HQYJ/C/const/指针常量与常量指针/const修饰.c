// const �ĺ�����ǳ���
// const int *p         p �ɱ�, *p ���ɱ�
// int const *p         p �ɱ�, *p ���ɱ�
// int *const p         p ���ɱ�, *p �ɱ�
// const int * const p  p ���ɱ�, *p ���ɱ�

// ����ָ����ָ�볣��
// 1������ָ��: const int *p(���ָ���ǳ���)    ������ָ����ָ���ֵ  
// 2��ָ�볣��: int *const p(���������ָ��)    ������ָ��
#include <stdio.h>

int main()
{
    /*�� 1
    int data; 
    int * const p = &data;

    data++;
    p++; // ����, ��Ϊ p �� const(ָ�볣��)
    (*p)++;
    */

    /*�� 2
    int data;
    const int * const p = &data; // ָ�������ɱ�

    data++;
    p++;
    (*p)++;
    */
    // my test
    int p = 30;
    const int *q = &p;
    *(q++);

    return 0;
}