#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// 初始化
void init(struct node *phead)
{
    phead->data = 0;
    phead->next = NULL;
}

// 尾插法插入元素
bool insert_val_tail(struct node *phead, int val)
{
    //当链表为空时直接插入
    struct node *pnew;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = val;
    pnew->next = NULL;
    if (phead->next == NULL)
    {
        phead->next = pnew;
        return true;
    }
    // 如果链表有元素
    struct node *find;
    for (find = phead; find->next != NULL; find = find->next)
    {}
    find->next = pnew;
    return true;
}

// 在某数值后面插入元素

// 打印链表
void print_linklist(struct node *phead)
{
    phead = phead->next;
    while (phead)
    {
        printf("%d ", phead->data);
        phead = phead->next;
    }
}

int main(void)
{
    struct node head;

    init(&head);
    insert_val_tail(&head, 10);
    insert_val_tail(&head, 20);
    insert_val_tail(&head, 30);
    print_linklist(&head);

    return 0;
}