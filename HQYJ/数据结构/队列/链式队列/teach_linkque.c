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

// 初始化2
void init_linkqueue(struct linkqueue *lq)
{
    lq->head.data = 0;
    lq->head.next = NULL;
    lq->front = lq->rear = &(lq->head);// 让队头队尾指向头节点
    return ;
}

// 进队列
bool en_linkqueue(struct linkqueue *lq, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    pnew->data = val;
    pnew->next = NULL;

    lq->rear->next = pnew;
    // !!!
    lq->rear = pnew;
    return true;
}

// my 进队列
bool my_enque(struct linkqueue *q)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    
}

// my 出队列
bool my_deque(struct linkqueue *lq)
{
    struct node *del, *prev;
    while (lq->rear != lq->front)
    {
        printf("in\n");
        // 指向有问题
        for (prev = lq->rear, del = prev->next; del->next != lq->front; prev = prev->next)
        {}
        printf("%d\n", del->data);
        prev->next = lq->front;
        free(del);
    }
    printf("All out\n");
}

// teacher 出队列
bool de_linkqueue(struct linkqueue *lq, int *pval)
{
    // 此时队列已空
    if (lq->front == lq->rear)
    return false;

    // [rear] <-- [  ] <-- [  ] <--[  ] <--[head(front)]
    struct node *ptemp;
    ptemp = lq->front->next;

    // 如果只有尾节点, 则让队尾重新指向头节点
    if (lq->front->next == lq->rear)
    {
        lq->rear = lq->front;
    }
    lq->front->next = lq->front->next->next;
    *pval =  ptemp->data;
    ptemp->next = NULL;
    free(ptemp);

    return true;
}

int main(void)
{
    int val;
    struct linkqueue que;
    init_linkqueue(&que);
    en_linkqueue(&que, 10);
    en_linkqueue(&que, 20);
    en_linkqueue(&que, 30);
    //my_deque(&que);
    while (de_linkqueue(&que, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}