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

int main()
{
    struct node head;
    init(&head);
    insert_val_tail(&head, 7);
    insert_val_tail(&head, 9);
    insert_val_tail(&head, 4);
    print(&head);

    return 0;
}