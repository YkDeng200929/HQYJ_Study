#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void init(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

bool enque(struct queue *q, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    pnew->data = val;
    pnew->next = NULL;
    // 头得指向第一个元素吧
    if (q->front == NULL && q->rear == NULL)
    {
        q->rear = pnew;
        q->front = pnew;
        return true;
    }
    // 一直插入
    pnew->next = q->rear;
    q->rear = pnew;
    return true;
}

bool deque(struct queue *q)
{
    struct node *head = NULL, *del = NULL;
    do
    {
        printf("%d\n", q->front->data);
        for (head = q->rear; head->next->next != NULL; head = head->next)
        {}
        del = head->next;
        head->next = NULL;
        free(del);
        q->front = head;
    }while (q->front != q->rear);
    if (q->front->next == NULL && q->rear->next == NULL)
    {
        printf("%d\n", q->front->data);
        //printf("before: %d %d\n", q->front, q->rear);
        free(q->front);
    }
    printf("deque ok\n");
}

int main(void)
{
    struct queue que;
    init(&que);
    enque(&que, 10);
    enque(&que, 20);
    enque(&que, 30);
    enque(&que, 40);
    //printf("%d %d\n", que.rear, que.front);
    deque(&que);
    //printf("%d %d\n", que.rear, que.front);
    //printf("%d %d\n", que.rear->next, que.front->next);

    return 0;
}