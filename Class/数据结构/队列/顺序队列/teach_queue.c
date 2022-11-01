#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

struct queue
{
    int data[MAX];
    int rear;
    int front;
};

bool enqueue(struct queue *q, int val)
{
    if(q->rear == MAX)
    return false;
    q->data[q->rear] = val;
    q->rear++;
    return true;
}

bool dequeue(struct queue *q, int *pval)
{
    if (q->front == q->rear)
    return false;
    *pval = q->data[q->front];
    q->front++;
    return true;
}

int main(void)
{
    struct queue que;
    int val;
    enqueue(&que, 10);
    enqueue(&que, 20);
    enqueue(&que, 30);
    while(dequeue(&que, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}