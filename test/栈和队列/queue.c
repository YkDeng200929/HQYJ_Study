#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

struct queue
{
    int data[MAX];
    int front;
    int rear;
};

void init(struct queue *q)
{
    memset(q->data, 0, sizeof(q->data));
    q->front = 0;
    q->rear = 0;
}

bool enque(struct queue *q, int val)
{
    if (q->rear == MAX)
    return false;
    q->data[q->rear] = val;
    q->rear++;
    return true;
}

bool deque(struct queue *q, int *pval)
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
    init(&que);
    enque(&que, 10);
    enque(&que, 20);
    enque(&que, 30);
    enque(&que, 40);
    enque(&que, 50);
    enque(&que, 50);
    enque(&que, 50);
    enque(&que, 50);
    int val;
    while (deque(&que, &val))
    {
        printf("%d\n", val);
    }
    enque(&que, 50);
    while (deque(&que, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}