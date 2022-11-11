#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX  5

typedef struct cir_que
{
    int data[MAX];
    int front;
    int rear;
} cir_que;

void init(cir_que *cq)
{
    for (int i = 0; i < MAX; i++)
    {
        cq->data[i] = 0;
    }
    cq->front = 0;
    cq->rear = 0;
}


bool judge_blank(cir_que *cq)
{
    if (cq->rear == cq->front)
    {
        return true;
    }
    return false;
}

bool judge_full(cir_que *cq)
{
    if (((cq->rear)+1)%MAX == cq->front)
    {
        return true;
    }
    return false;
}

bool insert_val(cir_que *cq, int val)
{
    if (judge_full(cq))
    {
        return false;
    }
    cq->data[cq->rear] = val;
    //(*count)++;
    cq->rear = (cq->rear + 1)%MAX;
    return 0;
}

int count(cir_que *cq)
{
    int num = 0;
    int count = cq->front;
    while ((count+1)%MAX != cq->front)
    {
        num++;
        count++;
    }
    return num;
}

int main(void)
{
    int len = 0;
    cir_que cq;
    init(&cq);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    insert_val(&cq, 10);
    if(judge_blank(&cq))
    {
        printf("blank\n");
    }
    len = count(&cq);
    printf("%d\n", len);

    return 0;
}