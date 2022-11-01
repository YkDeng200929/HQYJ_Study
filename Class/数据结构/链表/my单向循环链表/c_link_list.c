#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 单向循环链表
struct node
{
    int data;
    struct node *next;
};

// 初始化  
void init(struct node *phead)
{
    phead->data = 0;
    phead->next = phead;
}

// 尾插 
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pcur;
    struct node *pnew;
    pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = val;
    pnew->next = pnew;
    // 链表为空时
    if (phead->next == phead)
    {
        phead->next = pnew;
        pnew->next = phead;
    }
    for (pcur = phead; pcur->next != phead; pcur = pcur->next)
    {}
    pcur->next = pnew;
    pnew->next = phead;
}

// 插入节点
bool insert_val(struct node *phead, int target ,int val)
{
    struct node *pnew, *pcur;
    pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = val;
    pnew->next = pnew;
    // 遍历整个链表查找 target
    for (pcur = phead->next; pcur != phead && pcur->data != target; pcur = pcur->next)
    {};
    // 以下说明没有target
    if (pcur->next == phead)
        return false;
    
    pnew->next = pcur->next;
    pcur->next = pnew;
    return true;
}

bool del_val(struct node *phead, int target)
{
    struct node *find, *temp;
    for (find = phead->next; find != phead && find->next->data != target; find = find->next)
    {}
    // 判断是否遍历到目标值
    if (find == phead)
        return false;
    // 当前 find 为 target 所在位置的前一个节点
    // 需要删除 find->next;
    // 将 find 链接到 find->next->next
    temp = find->next;
    find->next = find->next->next;
    // 将 find->next 移除链表
    free(temp);
    return true;
}

// 打印链表
void print_link(struct node *phead)
{
    struct node *print;
    for(print = phead->next; print != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

bool josephr(struct node *phead, int k, int m)
{
    struct node *find_k, *find_m;
    int count = 1;
    // 如果队列不为空
    while (phead->next != phead)
    {
    // 寻找 k
    for (find_k = phead->next; find_k != phead && find_k->data != k; find_k = find_k->next)
    {}
    // 找到 k
    for (find_m = find_k; count <= m; find_m = find_m->next)
    {
        count++;
    }
    //  找到 m
    // 推出节点
    del_val(phead, find_m->data);
    }
    printf("全部出队\n");
    return true;
}

int main(void)
{
    struct node head;
    init(&head);
    int arr[8] = {6,2,7,4,3,5,1,8};
    for (int i = 0; i < 8; i++)
    {
        insert_val_tail(&head, arr[i]);
    }
    print_link(&head);
    josephr(&head, 3, 4);


    return 0;
}