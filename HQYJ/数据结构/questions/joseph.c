#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

bool insert_data_tail(struct node *phead, int val)
{
    struct node *pcur;
    struct node *pnew;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    // ��ʼ���½ڵ�
    pnew->data = val;
    pnew->next = pnew;
    // ���ֻ��һ���ڵ�, ֱ�Ӳ��� 
    if (phead->next == phead)
    {
        printf("ֻ��һ���ڵ�\n");
        // ͷ�� next ָ�� pnew
        phead->next = pnew;
        // pnew �� next ָ�� phead
        pnew->next = phead;
        printf("�������\n");
        return true;
    }
    // ����Ѿ����ڽڵ�, ����������
    for (pcur = phead->next; pcur != phead; pcur = pcur->next)
    {}
    // ��ʱ�Ѿ�������β��
    printf("����ڵ�\n");
    pcur->next = pnew;
    pnew->next = phead;
    return true;
}

void init(struct node *phead)
{
    phead->data = 1;
    phead->next = phead;
}


void print_cycle(struct node *phead)
{
    struct node *print;
    for (print = phead; print != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

int main(void)
{
    struct node cycle;
    init(&cycle);
    printf("1");
    insert_data_tail(&cycle, 1);
    printf("2");
    insert_data_tail(&cycle, 2);
    printf("3");
    insert_data_tail(&cycle, 3);
    printf("4");
    insert_data_tail(&cycle, 4);
    printf("�������\n");
    print_cycle(&cycle);
    printf("%d ", cycle.data);
    printf("%d ", cycle.next->data);
    printf("%d ", cycle.next->next->data);
    printf("%d ", cycle.next->next->next->data);
    //printf("%d ", cycle.data);

    return 0;
}