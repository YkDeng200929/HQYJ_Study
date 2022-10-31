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

bool dequeue(struct queue *q)
{
}

int main(void)
{


    return 0
}