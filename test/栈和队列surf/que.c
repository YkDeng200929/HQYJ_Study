#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

struct sequeue
{
    int data[5];
    int front;
    int rear;
};

void init(struct sequeue *s)
{
    memset(s->data, 0, sizeof(s->data));
    s->front = 0;
    s->rear = 0;
}

bool enque(struct sequeue *s, int val)
{
    if (s->rear == MAX)
    return false;
    s->data[s->rear] = val;
    s->rear++;
    return true;
}

bool deque(struct sequeue *s, int *pval)
{
    if(s->front == s->rear)
    return false;
    *pval = s->data[s->front];
    s->front++;
    return true;
}

int main(void)
{
    struct sequeue sque;
    init(&sque);
    enque(&sque, 10);
    enque(&sque, 20);
    enque(&sque, 30);
    enque(&sque, 40);
    int val;
    while (deque(&sque, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}