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
    phead->data = 0;
    phead->next = NULL;
}

bool insert_val_tail(struct node *phead, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = val;
    pnew->next = NULL;

    if(phead->next == NULL)
    {
        phead->next = pnew;
        return true;
    }
    struct node *pcur;
    for (pcur = phead;  pcur->next != NULL; pcur = pcur->next)
    {}
    if (pcur == NULL)
        return false;
    pcur->next = pnew;
    return true;
}

void print(struct node *phead)
{
    struct node *print = phead->next;
    do
    {
        printf("%d ", print->data);
        print = print->next;
    } while (print != NULL);

    putchar('\n');
}

bool rev(struct node *phead)
{
    struct node *prev = phead;
    struct node *mid = prev->next;
    struct node *after = NULL;
    while (mid != NULL)
    {
        after = mid->next;
        mid->next = prev;
        prev = mid;
        mid = after;
    }
    //prev->next = phead->next;
    phead->next->next = NULL;
    //phead->next->next = NULL;
    phead->next = prev;
    return true;
}

int main(void)
{
    struct node head;
    init(&head);
    insert_val_tail(&head, 10);
    insert_val_tail(&head, 20);
    insert_val_tail(&head, 30);
    insert_val_tail(&head, 40);
    print(&head);
    rev(&head);
    print(&head);

    return 0;
}