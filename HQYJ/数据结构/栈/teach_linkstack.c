#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void init_linkstack(struct linkstack *ls)
{
    ls->top = NULL;
}

bool push_linkstack(struct linkstack *ls, int val)
{
    struct node *pnew;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = val;
    pnew->next = NULL;

    pnew->next = ls->top;
    ls->top = pnew;
    return true;
}

bool get_top_val(struct linkstack *ls, int *pval)
{
    if (ls->top == NULL)
        return false;

    *pval = ls->top->data;
    return true;
}

bool out(struct linkstack *ls)
{
    struct node *fre;
    while(ls->top != NULL)
    {
        //if (ls->top == NULL)
        //break;
        printf("%d\n", ls->top->data);
        fre = ls->top;
        ls->top = ls->top->next;
        fre->next = NULL;
        free(fre);
    }
    printf("All out\n");
    return true;
}

bool pop_val(struct linkstack *ls, int *pval)
{
    if (ls->top == NULL)
    return false;
    struct node *ptmp;
    ptmp = ls->top;
    *pval = ptmp->data;
    ls->top = ls->top->next;
    ptmp->next = NULL;
    free(ptmp);
    return true;

}

void print(struct linkstack *ls)
{
    // 直接用 ls 作为值操作
    /*
    do
    {
        printf("%d ", ls->top->data);
        // 这里就会直接改变 值
        ls->top = ls->top->next;
    } while(ls->top != NULL);
    */
    struct node *print = ls->top;
    do
    {
        printf("%d ", print->data);
        print = print->next;     
    } while(print != NULL);
}

int main(void)
{
    struct linkstack lstk;
    init_linkstack(&lstk);
    push_linkstack(&lstk, 10);
    push_linkstack(&lstk, 20);
    push_linkstack(&lstk, 30);
    push_linkstack(&lstk, 40);
    print(&lstk);
    out(&lstk);
    int val;
    //pop_val(&lstk, &val);
    //while (pop_val(&lstk, &val))
    //{
    //    printf("%d", val);
    //}

    return 0;
}