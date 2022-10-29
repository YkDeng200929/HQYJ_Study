#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
// 初始化
void init(struct node *phead)
{
    phead->data = 6;
    phead->next = phead;
}

// 插入元素
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pnew = NULL;
    struct node *find;
    pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = val;
    pnew->next = pnew;
    // 当除头元素外没有元素
    if (phead->next == phead)
    {
        pnew->next = phead;
        phead->next = pnew;
        return true;
    }
    // 当存在多个元素
    for (find = phead; find->next != phead; find = find->next)
    {}
    if (find->next == phead)
    {
        pnew->next = phead;
        find->next = pnew;
        return true;
    }
    return false;
}

// 打印
void print(struct node *phead)
{
    struct node *print;
    for (print = phead; print->next != phead; print = print->next)
    {
        printf("%d ", print->data);
    }
    printf("%d ", print->data);
    putchar('\n');
}

// 出队 (ok
struct node * out(struct node *phead, int k, int m)
{
    struct node *find_k, *prev, *del;
    int count = 1;
    for (find_k = phead; find_k->data != k; find_k = find_k->next)
    {}
    // 基于 find_k 来出队
    while (find_k->next != find_k)
    {
        prev = find_k, del = prev->next;
        for (count = 1; count < m; prev = prev->next, del = prev->next, count++)
        {}
        if (del == find_k)
        {
            prev = prev->next;
            del = prev->next;
            prev->next = del->next;
            free(del);
            continue;
        }
        prev->next = del->next;
        free(del);
    }
    printf("find_k:%d, phead: %d\n", find_k->data, phead->data);
    printf("p_k: %d, p_k_next: %d\n", find_k, find_k->next);
    
    return find_k;
}    


// 插入目标元素 
void josepher(struct node *phead)
{
    insert_val_tail(phead, 2);
    insert_val_tail(phead, 7);
    insert_val_tail(phead, 4);
    insert_val_tail(phead, 3);
    insert_val_tail(phead, 5);
    insert_val_tail(phead, 1);
    insert_val_tail(phead, 8);
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    init(head);
    josepher(head);
    print(head);
    // k = 3, m = 4;
    printf("OK\n");
    head = out(head, 4, 3);
    printf("outok\n");
    print(head);

    return 0;
}