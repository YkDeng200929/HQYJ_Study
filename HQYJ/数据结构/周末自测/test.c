#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
// 初始化
void init(struct node *phead)
{
    phead->data = 6;
    phead->next = phead;
}

// 插入元素
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pnew = NULL;
    struct node *find;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = val;
    pnew->next = pnew;
    // 当除头元素外没有元素
    if (phead->next == phead)
    {
        pnew->next = phead;
        phead->next = pnew;
        return true;
    }
    // 当存在多个元素
    for (find = phead; find->next != phead; find = find->next)
    {}
    if (find->next == phead)
    {
        pnew->next = phead;
        find->next = pnew;
        return true;
    }
    return false;
}

// 打印
void print(struct node *phead)
{
    struct node *print;
    for (print = phead; print->next != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
        printf("%d ", print->data);
    putchar('\n');
}

// 出队
bool out(struct node *phead, int k, int m)
{
    struct node *find_k, *find_m;
    struct node *head;
    int count = 1;
    for (find_k = phead; find_k->next->data != k; find_k = find_k->next)
    {}
    // 让头等于 k 的地址 
    head = find_k->next;
    // 基于 head 来出队
    while (head->next != head)
    {
        find_m = head;
        for (count = 1; count <= m; count++)
        {
            find_m = find_m->next;
        }
        find_m->next = find_m->next->next;
        free(find_m);
    }
}

// 插入目标元素 
void josepher(struct node *phead)
{
    insert_val_tail(phead, 2);
    insert_val_tail(phead, 7);
    insert_val_tail(phead, 4);
    insert_val_tail(phead, 3);
    insert_val_tail(phead, 5);
    insert_val_tail(phead, 1);
    insert_val_tail(phead, 8);
}

int main()
{
    struct node head;
    init(&head);
    josepher(&head);
    print(&head);
    // k = 3, m = 4;
    out(&head, 3, 4);
    print(&head);

    return 0;
}