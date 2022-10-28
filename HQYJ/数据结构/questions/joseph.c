#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

bool insert_data_tail(struct node *phead, int val)
{
    struct node *pcur;
    struct node *pnew;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    // 初始化新节点
    pnew->data = val;
    pnew->next = pnew;
    // 如果只有一个节点, 直接插入 
    if (phead->next == phead)
    {
        printf("只有一个节点\n");
        // 头的 next 指向 pnew
        phead->next = pnew;
        // pnew 的 next 指向 phead
        pnew->next = phead;
        printf("插入完毕\n");
        return true;
    }
    // 如果已经存在节点, 则在最后插入
    for (pcur = phead->next; pcur != phead; pcur = pcur->next)
    {}
    // 此时已经遍历到尾部
    printf("多个节点\n");
    pcur->next = pnew;
    pnew->next = phead;
    return true;
}

void init(struct node *phead)
{
    phead->data = 1;
    phead->next = phead;
}


void print_cycle(struct node *phead)
{
    struct node *print;
    for (print = phead; print != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

int main(void)
{
    struct node cycle;
    init(&cycle);
    printf("1");
    insert_data_tail(&cycle, 1);
    printf("2");
    insert_data_tail(&cycle, 2);
    printf("3");
    insert_data_tail(&cycle, 3);
    printf("4");
    insert_data_tail(&cycle, 4);
    printf("插入完毕\n");
    print_cycle(&cycle);
    printf("%d ", cycle.data);
    printf("%d ", cycle.next->data);
    printf("%d ", cycle.next->next->data);
    printf("%d ", cycle.next->next->next->data);
    //printf("%d ", cycle.data);

    return 0;
}