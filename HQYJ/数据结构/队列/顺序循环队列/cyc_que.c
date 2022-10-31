#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 5

struct circle_queue
{
    int data[MAX];
    int front;
    int rear;
};

void init(struct circle_queue *cq)
{
    cq->front = 0;
    cq->rear = 0;
    memset(cq->data, 0, sizeof(cq->data));
}

bool encirque(struct circle_queue *cq, int val)
{
    if ((cq->rear+1)%MAX == cq->front)
    return false;
    //cq->data[cq->rear] == val;
    cq->data[cq->rear] = val;
    //cq->rear = (cq->rear)%MAX + 1;
    cq->rear = (cq->rear + 1)%MAX;
    return true;
}

bool decirque(struct circle_queue *cq, int *pval)
{
    //if ((cq->rear+1)%MAX == cq->front)
    if (cq->rear == cq->front)
    return false;
    *pval = cq->data[cq->front];
    cq->front =  (cq->front+1)%MAX;
    return true;
}

int main(void)
{
    struct circle_queue que;
    init(&que);
    encirque(&que, 10);
    encirque(&que, 20);
    encirque(&que, 30);
    encirque(&que, 40);
    int val;
    while (decirque(&que, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}