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

int main(void)
{
    struct node head;
    init(&head);
    insert_val_tail(&head,10);
    insert_val_tail(&head,20);
    insert_val_tail(&head,30);
    insert_val_tail(&head,40);
    insert_val_tail(&head,50);
    insert_val_tail(&head,60);
    print_link(&head);
    insert_val(&head, 20, 33);
    print_link(&head);


    return 0;
}