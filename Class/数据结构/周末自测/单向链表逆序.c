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

// 尾插
bool insert(struct node *phead, int val)
{
    struct node *pnew = NULL;
    struct node *find;
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
    for (find = phead; find->next != NULL; find = find->next)
    {}
    if (!find)
        return false;
    find->next = pnew;
    return true;
}

// 打印
void print(struct node *phead)
{
    while(phead != NULL)
    {
        phead = phead->next;
        printf("%d ", phead->data);
    }
    putchar('\n');
    return ;
}

void print2(struct node *phead)
{
    struct node *print;
    for (print = phead->next; print != NULL; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
    return ;
}

bool rev(struct node *phead)
{
    struct node *prev, *mid, *aft;
    for (prev = phead->next, mid = prev->next, aft = mid->next; mid != NULL; prev = prev->next, mid = prev->next, aft = mid->next)
    {
        printf("ok");
        mid->next = prev;
        prev->next = mid;
        mid = aft;
        aft = mid->next;
        mid->next = prev->next;
        if(phead->next == prev)
        {
            prev->next = NULL;
        }
        prev = mid->next;
    }
    phead->next = mid;
}

int main()
{
    struct node head;
    init(&head);
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    printf("ok");
    print2(&head);
    rev(&head);
    printf("okrev");
    print2(&head);

    return 0;
}