#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

bool insert(struct node *phead, int val)
{
    struct node *pnew, *find;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->next = NULL;
    pnew->data = val;
    if (phead->next == NULL)
    {
        phead->next = pnew;
        return true;
    }
    for(find = phead; find->next != NULL; find = find->next)
    {}
    if (!find)
    {
        printf("error\n");
        return false; 
    }
    find->next = pnew;
    return true;
}

void print_list(struct node *phead)
{
    struct node *print;
    for (print = phead->next; print != NULL; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

bool rev(struct node *phead)
{
    struct node *prev = phead;
    struct node *mid = prev->next;
    struct node *after = mid->next;

    while (mid != NULL)
    {
        after = mid->next;
        mid->next = prev;
        prev = mid;
        mid = after;
    }
    phead->next->next = NULL;
    phead->next = prev;
    return true;

}

void print2(struct node *phead)
{
    phead = phead->next;
    while (phead != NULL)
    {
        printf("%d ", phead->data);
        phead = phead->next;
    }
    putchar('\n');
}

int main()
{
    struct node head;
    init(&head);
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    print2(&head);
    rev(&head);
    print2(&head);
    return 0;
}