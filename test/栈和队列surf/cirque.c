#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

struct cir_que
{
    int data[MAX];
    int front;
    int rear;
};

void init(struct cir_que *cq)
{
    memset(cq->data, 0, sizeof(cq->data));
    cq->front = cq->rear = 0;
}

bool enque(struct cir_que *cq, int val)
{
    if ((cq->rear + 1) % MAX == cq->front)
    return false;
    cq->data[cq->rear] = val;
    cq->rear = (cq->rear + 1) % MAX;
    return true;
}

bool deque(struct cir_que *cq, int *pval)
{
    if (cq->rear == cq->front)
    return false;
    *pval = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAX;
    return true;
}

int main(void)
{
    struct cir_que cq;
    init(&cq);
    enque(&cq, 10);
    enque(&cq, 20);
    enque(&cq, 30);
    enque(&cq, 40);
    int val;
    printf("1\n");
    while (deque(&cq, &val))
    {
        printf("%d\n", val);
    }
    enque(&cq, 50);
    enque(&cq, 60);
    printf("2\n");
    while (deque(&cq, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}