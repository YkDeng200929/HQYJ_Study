// Ë«ÏòÑ­»·Á´±í
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void init(struct node *phead)
{
    phead->data = 0;
    phead->prev = phead->next  = phead;
}

bool insert_val(struct node *phead, int val)
{
    struct node *pnew =  (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    pnew->data = val;
    pnew->next = pnew->prev = pnew;
    
    pnew->prev->next = pnew;
    pnew->next = phead;
    pnew->prev = pnew;
    return true;
}

void print_list(struct node *phead)
{
    do
    {
        printf("%d ", phead->data);        
    } while (phead->next != phead);
    putchar('\n');
}

int main(void)
{
    struct node phead;
    init(&phead);
    insert_val(&phead, 10);
    insert_val(&phead, 30);
    insert_val(&phead, 40);
    print_list(&phead);

    return 0;
}