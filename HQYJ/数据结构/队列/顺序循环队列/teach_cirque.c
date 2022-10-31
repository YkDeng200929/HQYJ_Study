#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

struct  circle_queue
{
    int data[MAX];
    int front;
    int rear;
};

// 初始化
void init_circle_que(struct circle_queue *cq)
{
    memset(cq, 0, sizeof(cq->data));
    cq->front = cq->rear = 0;
}

// 入队
bool en_circle_queue(struct circle_queue *cq, int val)
{
    // 满
    if ((cq->rear + 1) % MAX == cq->front)
    return false;

    // 如果有元素
    cq->data[cq->rear] = val;
    // 因为是循环队列, 所以数组下标是动态的
    cq->rear = (cq->rear + 1) % MAX;

    return true;
}

// 出队
bool de_circle_queue(struct circle_queue *cq, int *pval)
{
    // 如果队列为空
    if (cq->rear == cq->front)
    return false;

    *pval = cq->data[cq->front];
    cq->front = (cq->front + 1) % MAX;
    return true;
}

int main(void)
{
    struct circle_queue c_que;
    init_circle_que(&c_que);
    en_circle_queue(&c_que, 10);
    en_circle_queue(&c_que, 20);
    en_circle_queue(&c_que, 30);
    en_circle_queue(&c_que, 40);
    en_circle_queue(&c_que, 50);
    en_circle_queue(&c_que, 60);
    int val;
    printf("first\n");
    while (de_circle_queue(&c_que, &val))
    {
        printf("%d\n", val);
    }
    en_circle_queue(&c_que, 60);
    en_circle_queue(&c_que, 70);
    en_circle_queue(&c_que, 80);
    // 循环队列再出队后还能继续进队
    printf("second\n");
    while (de_circle_queue(&c_que, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}