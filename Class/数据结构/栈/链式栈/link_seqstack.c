#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node *next;
};

struct linkstack
{
    struct node *top;
};

void init(struct linkstack *ls)
{
    ls->top = NULL;
}

bool push_val(struct linkstack *ls, int val)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    if (!new)
        return false;
    new->data = val;
    if(ls->top == NULL)
    {
        //printf("Only one\n");
        ls->top = new;
        new->next = NULL;
        return true;
    }
    //printf("Multi\n");
    new->next = ls->top;
    ls->top = new;
    return true;
}

void print(struct linkstack *ls)
{
    struct node *print;
    for (print = ls->top; print != NULL; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

bool pop_val(struct linkstack *ls)
{
    struct node *below, *del;
    printf("Out stack:\n");
    for (del = ls->top; del != NULL;)
    {
        printf("%d\n", del->data);
        below = del->next;
        free(del);
        del = below;
    }
}


int main(void)
{
    struct linkstack ls;
    init(&ls);
    push_val(&ls, 10);
    push_val(&ls, 20);
    push_val(&ls, 30);
    push_val(&ls, 40);
    printf("Insert ok\n");
    print(&ls);
    pop_val(&ls);

    return 0;
}