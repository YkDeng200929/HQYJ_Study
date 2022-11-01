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

// ��ʼ��
void init_circle_que(struct circle_queue *cq)
{
    memset(cq, 0, sizeof(cq->data));
    cq->front = cq->rear = 0;
}

// ���
bool en_circle_queue(struct circle_queue *cq, int val)
{
    // ��
    if ((cq->rear + 1) % MAX == cq->front)
    return false;

    // �����Ԫ��
    cq->data[cq->rear] = val;
    // ��Ϊ��ѭ������, ���������±��Ƕ�̬��
    cq->rear = (cq->rear + 1) % MAX;

    return true;
}

// ����
bool de_circle_queue(struct circle_queue *cq, int *pval)
{
    // �������Ϊ��
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
    // ѭ�������ٳ��Ӻ��ܼ�������
    printf("second\n");
    while (de_circle_queue(&c_que, &val))
    {
        printf("%d\n", val);
    }

    return 0;
}