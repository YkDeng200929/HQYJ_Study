#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct linkseq
{
    struct node *top;
};

void init(struct linkseq *ls)
{
    ls->top = NULL;
}

bool push_lstk(struct linkseq *ls, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    pnew->data = val;
    pnew->next = NULL;

    pnew->next = ls->top;
    ls->top = pnew;
    return true;
}

bool pop_lkstk(struct linkseq *ls, int *pval)
{
    if (ls->top == NULL)
    return false;
    *pval = ls->top->data;
    ls->top = ls->top->next;
    return true;
}

int main(void)
{
    struct linkseq lkstk;
    init(&lkstk);
    push_lstk(&lkstk, 10);
    push_lstk(&lkstk, 20);
    push_lstk(&lkstk, 30);
    push_lstk(&lkstk, 40);
    int val;
    while (pop_lkstk(&lkstk, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}