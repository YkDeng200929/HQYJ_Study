#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

struct stack
{
    int data[MAX];
    int top;
};

void init(struct stack *stk)
{
    memset(stk->data, 0, sizeof(stk->data));
    int top = -1;
}

bool push_stk(struct stack *stk, int val)
{
    if (stk->top == MAX)
    return false;
    stk->data[++stk->top] = val;
    return false;
}

bool pop_stk(struct stack *stk, int *pval)
{
    if (stk->top == 0)
    return false;
    *pval = stk->data[stk->top];
    stk->top--;
    return true;
}

int main(void)
{
    struct stack stk;
    init(&stk);
    push_stk(&stk, 10);
    push_stk(&stk, 20);
    push_stk(&stk, 30);
    push_stk(&stk, 40);
    int val;
    while (pop_stk(&stk, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}