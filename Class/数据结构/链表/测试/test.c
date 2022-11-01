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
void init_link(struct node *head)
{
    head->data = 0;
    head->next = NULL;
}

// 插入元素
bool insert_val_tail(struct node *head, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node))
    if (pnew == NULL)
        return false;
    pnew->data = val;
    pnew->data = NULL;

    struct node *pcur;
    for (pcur = head; pcur->next != NULL; pcur = pcur->next)
    {}
    pcur->next = head;
    return true;
}

// 中间插入元素
bool insert_val_after(struct node *head, int val, int newval)
{
    struct node *pcur;

    for (pcur = head->next; pcur != NULL && pcur->data != val; pcur->next)
    {}
    if (!pcur)
        return false;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = newval;
    pnew->next = NULL;

    pnew->next = pcur->next;
    pcur->next = pnew;
}

int main()
{
    return 0;
}