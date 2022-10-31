#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

struct cir_que
{
    int data[MAX];
    int front;
    int rear;
};

void init(struct cir_que *cq)
{
    cq->front = 0;
    cq->rear = 0;
    memset(cq->data, 0, sizeof(cq->data));
}

bool enque(struct cir_que *cq, int val)
{
    if ((cq->rear+1)%MAX == cq->front)
    return false;
    cq->data[cq->rear] = val;
    cq->rear = (cq->rear+1)%MAX;
    return true;
}

bool deque(struct cir_que *cq, int *pval)
{
    if (cq->rear == cq->front)
    return false;
    *pval = cq->data[cq->front];
    cq->front = (cq->front+1)%MAX;
    return true;
}

int main(void)
{
    struct cir_que cque;
    init(&cque);
    enque(&cque, 10);
    enque(&cque, 20);
    enque(&cque, 30);
    enque(&cque, 40);
    int val;
    while (deque(&cque, &val))
    {
        printf("%d\n", val);
    }

    return  0;
}