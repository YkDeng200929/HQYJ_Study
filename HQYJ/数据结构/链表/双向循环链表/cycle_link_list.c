#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// 初始化
void init_clinklist(struct node *phead)
{
    phead->data = 0;
    phead->prev = phead->next = phead;
    return ;
}

// my 尾插
bool my_insert_val_tail(struct node *phead, int val)
{
    struct node *new_node, *find;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return false;
    new_node->data = val;

    // 如果链表为空
    if (phead->next == phead)
    {
        new_node->next = phead;
        new_node->prev = phead;
        phead->next = new_node;
        phead->prev = new_node;
        return true;
    }
    // 如果链表非空
    for (find = phead; find != phead->prev; find = find->next)
    {}
    find->next->prev = new_node;
    find->next = new_node;
    new_node->prev = find;
    new_node->next = find->next;
}

// teacher 尾插
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    // 初始化新节点
    pnew->data = val;
    pnew->prev = pnew->next = pnew;

    // 将新节点的头指向 phead 的前一个节点位置
    pnew->prev = phead->prev;
    // 将新节点的尾指向 phead 
    pnew->next = phead;
    // 完成新节点头尾的插入

    // phead 前一个节点的尾连上 pnew
    phead->prev->next = pnew;
    // phead 的头指向 pnew
    phead->prev = pnew;

    return true;
}

// my 在元素的尾部插入
bool my_insert_val_after(struct node *phead, int target, int val)
{
    // 创建新节点
    struct node *new_node = NULL;
    struct node *pcur;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return false;
    // 初始化新节点
    new_node->data = val;
    new_node->prev = new_node->next = new_node;

    // 找到目标值
    // 1、遍历链表 直到头
    for (pcur = phead->next; pcur != phead && pcur->data != target; pcur = pcur->next)
    {}
    // 2、判断是否找到目标值
    if (pcur == phead)
        return false;// 未找到目标值
    // 若找到目标值, 则插入
    // 将新节点的 next 指向 pcur
    //new_node->next = pcur;
    new_node->next = pcur->next;
    // 将新节点的 prev 指向 pcur->prev
    //new_node->prev = pcur->prev;
    new_node->prev = pcur;
    // 将 pcur 的 prev 指向 new_node
    //pcur->prev = new_node;
    pcur->next->prev = new_node;
    // 将 pcur->prev 的 next 指向 new_node
    pcur->next = new_node;

    return true;
}

// teacher 在中间插入

bool insert_val_after(struct node *phead, int val, int newval)
{
    struct node *pcur;

    for (pcur = phead->next; pcur != phead && pcur->data != val; pcur = pcur->next)
    {}
    if (pcur == phead)
        return false;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));

    //初始化pnew
    pnew->data = newval;
    pnew->prev = pnew->next = pnew;

    pnew->prev = pcur;
    pnew->next = pcur->next;

    pcur->next->prev = pnew;
    pcur->next = pnew;

    return true;
}

// my 删除节点
bool my_delete_val(struct node *phead, int target)
{
    // 遍历 phead, 找到 target
    struct node *pcur = NULL;
    for (pcur = phead->next; pcur != phead && pcur->data != target; pcur = pcur->next)
    {}
    if (pcur == phead)
        return false;
    // 此时表示 pcur->data == target, 应释放 pcur
    // pcur 前置节点 的 next 应指向 pcur 的下一个节点
    //pcur->next = pcur->next->next;
    pcur->prev->next = pcur->next;
    // pcur 的下一个节点的 prev 应指向 pcur 的前一个节点
    pcur->next->prev = pcur->prev;

    // 已经首位链接
    pcur->next = pcur->prev = NULL;
    free(pcur);
}

// teacher 删除节点
bool delete_val(struct node *phead, int val)
{
    struct node *pdel;
    for (pdel = phead->next; pdel != phead && pdel->data != val; pdel = pdel->next)
    {}
    if (pdel == phead)
        return false;
    
    // 
    pdel->prev->next = pdel->next;
    pdel->next->prev = pdel->prev;
    
    pdel->prev = pdel->next = NULL;
    free(pdel);
    return true;
}

// my print
void my_print(struct node *phead)
{
    struct node *find = NULL;
    find = phead->next;
    for (; find != phead->prev; find = find->next)
    {
        printf("%d ", find->data);
    }
    printf("%d ", find->data);
    putchar('\n');
}

// teacher print
void print_clinklist(struct node *phead)
{
    struct node *pcur;
    for (pcur = phead->next; pcur != phead; pcur = pcur->next)
    {
        printf("%d ", pcur->data);
    }
}

int main(void)
{
    struct node head;
    init_clinklist(&head);
    insert_val_tail(&head, 10);
    insert_val_tail(&head, 20);
    insert_val_tail(&head, 30);
    insert_val_tail(&head, 40);
    print_clinklist(&head);
    my_insert_val_after(&head, 20, 33);
    printf("插入后\n");
    print_clinklist(&head);
    //delete_val(&head, 40);
    my_delete_val(&head, 20);
    printf("删除后\n");
    print_clinklist(&head);

    return 0;
}