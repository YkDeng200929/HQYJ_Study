#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct linkqueue
{
    struct node head;
    struct node *front;
    struct node *rear;
};

// 初始化
void my_init(struct linkqueue *q)
{
    q->head.data = 0;
    q->head.next = NULL;
    q->front = NULL;
    q->rear = NULL;
}

void init_linkqueue(struct linkqueue *lq)
{
    lq->head.data = 0;
    lq->head.next = NULL;
    lq->front = lq->rear = &(lq->head);// 让队头队尾指向头节点
    return ;
}

bool en_linkqueue(struct linkqueue *lq, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    pnew->data = val;
    pnew->next = NULL;

    lq->rear->next = pnew;
    return true;
}

// my enque
bool my_enque(struct linkqueue *q)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    
}

// my dequeue
bool my_deque(struct linkqueue *lq)
{
    struct node *del, *prev;
    while (lq->rear->next != lq->front)
    {
        for (prev = lq->rear->next, del = prev->next; del->next != lq->front; prev = prev->next)
        {}
        printf("%d\n", del->data);
        prev->next = lq->front;
        free(del);
    }
    printf("All out\n");
}

int main(void)
{
    struct linkqueue que;
    init_linkqueue(&que);
    en_linkqueue(&que, 10);
    en_linkqueue(&que, 20);
    en_linkqueue(&que, 30);
    my_deque(&que);

    return 0;
}