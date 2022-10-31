#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10


struct seqstack
{
    int data[MAX];
    int top;
};

void init(struct seqstack *pstk)
{
    memset(pstk->data, 0, sizeof(pstk->data));
    pstk->top = -1;
    return ;
}

// my 输入元素
bool my_push_seqstack(struct seqstack *pstk, int val)
{
    if (pstk->top == MAX-1)
        return false;
    if (pstk->top <= MAX-1)
    {
        pstk->data[pstk->top + 1] = val;
        pstk->top++;
        return true;
    }
    return false;
}

// teacher  输入元素 (有问题)
bool push_seqstack(struct seqstack *pstk, int val)
{
    if(pstk->top == MAX - 1)
    pstk->top++;
    pstk->data[pstk->top] = val;
    return true;
}

// my 得到栈顶元素
bool my_get_top_val(struct seqstack *pstk, int *pval)
{
    for (int i = pstk->top; i > -1; i--)
    {
        if (pstk->data[i] == 0)
            continue;
        *pval = pstk->data[i];
        return true;
    }
    return false;
}

// teacher 得到栈顶元素
bool get_top_val(struct seqstack *pstk, int *pval)
{
    if(pstk->top == -1)
        return false;
    *pval = pstk->data[pstk->top];
    return true;
}

// my 出栈(意思理解错了)
bool my_pop_val(struct seqstack *pstk, int val)
{
    int i;
    for (i = pstk->top; i > -1 && pstk->data[i] != val; i--)
    {}
    if (i == -1)
        return false;
    for (i; i < pstk->top; i++)
    {
        pstk->data[i] = pstk->data[i+1];
    }
    pstk->top--;
    return true;
}

// teacher 出栈(也就是让栈中的元素依次出去)
bool pop_val(struct seqstack *pstk, int *pval)
{
    if (pstk->top == -1)
        return false;
    *pval = pstk->data[pstk->top];
    pstk->top--;
    return true;
}

void print(struct seqstack *pstk)
{
    for (int i = 0; i < MAX-1; i++)
    {
        printf("%d ", pstk->data[i]);
    }
    putchar('\n');
}

int main(void)
{
    struct seqstack stk;
    init(&stk);
    my_push_seqstack(&stk, 10);
    my_push_seqstack(&stk, 20);
    my_push_seqstack(&stk, 30);
    my_push_seqstack(&stk, 40);
    print(&stk);
    int val = 0;
    get_top_val(&stk, &val);
    printf("%d\n", val);
    //my_pop_val(&stk, 20);
    print(&stk);
    int value;
    while (pop_val(&stk, &value))
    {
        printf("%d\n", value);
    }

    return 0;
}