#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����ѭ������
struct node
{
    int data;
    struct node *next;
};

// ��ʼ�� (û����) 
void init(struct node *phead)
{
    phead->data = 6;
    phead->next = phead;
}

// β�� (û����)
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

// ����ڵ� (û����)
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

// ɾ���ڵ� (�޷�ɾ��ͷ�ڵ�)
bool del_val(struct node *phead, int target)
{
    struct node *prev, *find, *trash;
    for (prev = phead, find = prev->next; find != phead && find->next->data != target; prev = prev->next, find = prev->next)
    {}
    // �ж��Ƿ������Ŀ��ֵ
    if (find == phead)
        return false;
    // ���Ŀ��ֵΪͷ�ڵ�
    if (phead->data == target && find->next->data == target)
    {
        trash = find;
        prev->next = find->next->next;
        free(trash);
        phead = find->next;
        printf("ͷ�ڵ�ɾ�����\n");
        return true;
    }
    // ��ǰ find Ϊ target ����λ�õ�ǰһ���ڵ�
    // ��Ҫɾ�� find->next;
    // �� find ���ӵ� find->next->next
    trash = find->next;
    find->next = find->next->next;
    // �� find->next �Ƴ�����
    free(trash);
    return true;
}

// ��ӡ���� (û����)
void print_link(struct node *phead)
{
    struct node *print;
    /*
    for(print = phead; print->next != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
    */
   //print = phead;
   //while (print->next != print)
}

// Լɪ��, �Ƴ����нڵ�
bool josephr(struct node *phead, int k, int m)
{
    struct node *find;
    int count = 1;
    // ������в�Ϊ�� (����: phead->next = phead)
    while (phead->next != phead)
    {
        // Ѱ�� k
        for (find = phead; find->data != k; find = find->next)
        {}
        // Ѱ�ҵ� m
        for (find; count <= m; find = find->next)
        {}
        // �Ƴ��ڵ�
        del_val(phead, find->data);
    }
}

int main(void)
{
    struct node head;
    init(&head);
    int arr[7] = {2,7,4,3,5,1,8};
    for (int i = 0; i < 7; i++)
    {
        insert_val_tail(&head, arr[i]);
    }
    //del_val(&head, 6);
    //print_link(&head);

    return 0;
}