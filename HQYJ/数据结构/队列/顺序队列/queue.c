#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 3

struct queue
{
    int data[MAX];
    int front;
    int rear;
};

void init_queue(struct queue *q)
{
    q->front = 0;
    q->rear = 0;
    memset(q->data, 0, sizeof(q->data));
}

bool enque(struct queue *q, int val)
{
    if (q->rear == MAX)
    return false;
    q->data[q->rear] = val;
    q->rear++;
    return true;
}

bool deque(struct queue *q)
{
    while (q->rear != 0)
    {
        printf("%d\n", q->data[q->front]);
        q->data[q->front] = 0;
        q->front = ++q->front;
        q->rear--;
    }
    printf("All out\n");
    return true;
}

bool new_deque(struct queue *q)
{
    // front 依次后移, 就代表头出队了
    while (q->front != q->rear)
    {
        printf("%d\n", q->data[q->front]);
        q->front++;
    }
}

int main(void)
{
    struct queue que;
    init_queue(&que);
    enque(&que, 10);
    enque(&que, 20);
    enque(&que, 30);
    enque(&que, 40);
    new_deque(&que);

    return 0;
}