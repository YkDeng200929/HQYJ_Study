#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����ѭ������
struct node
{
    int data;
    struct node *next;
};

// ��ʼ��  
void init(struct node *phead)
{
    phead->data = 0;
    phead->next = phead;
}

// β�� 
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pcur;
    struct node *pnew;
    pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = val;
    pnew->next = pnew;
    // ����Ϊ��ʱ
    if (phead->next == phead)
    {
        phead->next = pnew;
        pnew->next = phead;
    }
    for (pcur = phead; pcur->next != phead; pcur = pcur->next)
    {}
    pcur->next = pnew;
    pnew->next = phead;
}

// ����ڵ�
bool insert_val(struct node *phead, int target ,int val)
{
    struct node *pnew, *pcur;
    pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = val;
    pnew->next = pnew;
    // ��������������� target
    for (pcur = phead->next; pcur != phead && pcur->data != target; pcur = pcur->next)
    {};
    // ����˵��û��target
    if (pcur->next == phead)
        return false;
    
    pnew->next = pcur->next;
    pcur->next = pnew;
    return true;
}

bool del_val(struct node *phead, int target)
{
    struct node *find, *temp;
    for (find = phead->next; find != phead && find->next->data != target; find = find->next)
    {}
    // �ж��Ƿ������Ŀ��ֵ
    if (find == phead)
        return false;
    // ��ǰ find Ϊ target ����λ�õ�ǰһ���ڵ�
    // ��Ҫɾ�� find->next;
    // �� find ���ӵ� find->next->next
    temp = find->next;
    find->next = find->next->next;
    // �� find->next �Ƴ�����
    free(temp);
    return true;
}

// ��ӡ����
void print_link(struct node *phead)
{
    struct node *print;
    for(print = phead->next; print != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

bool josephr(struct node *phead, int k, int m)
{
    struct node *find_k, *find_m;
    int count = 1;
    // ������в�Ϊ��
    while (phead->next != phead)
    {
    // Ѱ�� k
    for (find_k = phead->next; find_k != phead && find_k->data != k; find_k = find_k->next)
    {}
    // �ҵ� k
    for (find_m = find_k; count <= m; find_m = find_m->next)
    {
        count++;
    }
    //  �ҵ� m
    // �Ƴ��ڵ�
    del_val(phead, find_m->data);
    }
    printf("ȫ������\n");
    return true;
}

int main(void)
{
    struct node head;
    init(&head);
    int arr[8] = {6,2,7,4,3,5,1,8};
    for (int i = 0; i < 8; i++)
    {
        insert_val_tail(&head, arr[i]);
    }
    print_link(&head);
    josephr(&head, 3, 4);


    return 0;
}