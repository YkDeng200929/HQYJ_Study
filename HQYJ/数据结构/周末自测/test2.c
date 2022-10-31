#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void init(struct node *phead)
{
    phead->data = 6;
    phead->next = phead;
}

bool insert_tail(struct node *phead, int val)
{
    struct node *pnew, *find;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    {
        printf("malloc pnew error\n");
        return false;
    }
    pnew->data = val;
    pnew->next = pnew;
    // ��ֻ��һ���ڵ�ʱֱ�Ӳ���
    if (phead->next == phead)
    {
        phead->next = pnew;
        pnew->next = phead;
        return true;
    }
    // ���ж��Ԫ��ʱ
    for(find = phead; find->next != phead; find = find->next)
    {}
    find->next = pnew;
    pnew->next = phead;

    return true;
}

void print(struct node *phead)
{
    while(phead->next != phead)
    {
        printf("%d ", phead->data);
        phead = phead->next;
    }
    printf("%d", phead->data);
    putchar('\n');
}

void print2(struct node *phead)
{
    struct node *print;
    for (print = phead; print->next != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    printf("%d ", print->data);
    putchar('\n');
}


struct node * out(struct node *phead, int k, int m)
{
    struct node *find_k, *del, *prev;
    // �ҵ� k
    for (find_k = phead; find_k->data != k; find_k = find_k->next)
    {}
    // ������ k �⻹�������ڵ�ʱ
    int count = 1;
    while(find_k->next != find_k)
    {
        for(prev = find_k, del = prev->next; count < m; prev = prev->next, del = prev->next, count++)
        {}
            // �������, del = find_k
            if (del == find_k)
            {
                prev = prev->next;
                del = prev->next;
                prev->next =del->next;
                free(del);
                continue;
            }
            prev->next = del->next;
            free(del);
    }
    printf("head: %d, head->next: %d\nhead->data: %d\n", find_k, find_k->next, find_k->data);
    return find_k;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    if (!head)
    {
        printf("Malloc error\n");
        return 0;
    }
    init(head);
    insert_tail(head, 2);
    insert_tail(head, 4);
    insert_tail(head, 9);
    insert_tail(head, 7);
    insert_tail(head, 3);
    insert_tail(head, 1);
    print2(head);
    head = out(head, 3, 4);
}