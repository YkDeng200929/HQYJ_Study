#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 单向循环链表
struct node
{
    int data;
    struct node *next;
};

// 初始化 (没问题) 
void init(struct node *phead)
{
    phead->data = 6;
    phead->next = phead;
}

// 尾插 (没问题)
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

// 插入节点 (没问题)
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

// 删除节点 (无法删除头节点)
bool del_val(struct node *phead, int target)
{
    struct node *prev, *find, *trash;
    for (prev = phead, find = prev->next; find != phead && find->next->data != target; prev = prev->next, find = prev->next)
    {}
    // 判断是否遍历到目标值
    if (find == phead)
        return false;
    // 如果目标值为头节点
    if (phead->data == target && find->next->data == target)
    {
        trash = find;
        prev->next = find->next->next;
        free(trash);
        phead = find->next;
        printf("头节点删除完毕\n");
        return true;
    }
    // 当前 find 为 target 所在位置的前一个节点
    // 需要删除 find->next;
    // 将 find 链接到 find->next->next
    trash = find->next;
    find->next = find->next->next;
    // 将 find->next 移除链表
    free(trash);
    return true;
}

// 打印链表 (没问题)
void print_link(struct node *phead)
{
    struct node *print;
    /*
    for(print = phead; print->next != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
    */
   //print = phead;
   //while (print->next != print)
}

// 约瑟夫, 推出所有节点
bool josephr(struct node *phead, int k, int m)
{
    struct node *find;
    int count = 1;
    // 如果队列不为空 (条件: phead->next = phead)
    while (phead->next != phead)
    {
        // 寻找 k
        for (find = phead; find->data != k; find = find->next)
        {}
        // 寻找到 m
        for (find; count <= m; find = find->next)
        {}
        // 推出节点
        del_val(phead, find->data);
    }
}

int main(void)
{
    struct node head;
    init(&head);
    int arr[7] = {2,7,4,3,5,1,8};
    for (int i = 0; i < 7; i++)
    {
        insert_val_tail(&head, arr[i]);
    }
    //del_val(&head, 6);
    //print_link(&head);

    return 0;
}