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
    cq->front = 0;
    cq->rear = 0;
}

bool en_cirque(struct cir_que *cq, int val)
{
    if ((cq->rear + 1) % MAX == cq->front)
    return false;
    cq->data[cq->rear] = val;
    cq->rear = (cq->rear + 1) % MAX;

    return true;
}

bool de_cirque(struct cir_que *cq, int *pval)
{
    if (cq->rear == cq->front)
    return false;
    *pval = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAX;
    return true;
}

int main(void)
{
    struct cir_que cque;
    init(&cque);
    en_cirque(&cque, 10);
    en_cirque(&cque, 20);
    en_cirque(&cque, 30);
    en_cirque(&cque, 40);
    int val;
    printf("First\n");
    while (de_cirque(&cque, &val))
    {
        printf("%d\n", val);
    }
    en_cirque(&cque, 50);
    printf("Second\n");
    while (de_cirque(&cque, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}