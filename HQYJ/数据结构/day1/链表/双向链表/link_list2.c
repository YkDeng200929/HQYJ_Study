#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// 初始化
void init_dlinklist(struct node *phead)
{
    phead->data = 0;
//  [ phead ]  --> [ phead->next ](prev) --> [  ]
    
    phead->prev = phead->next = NULL;
}

// my 插入元素(尾插) :: 结合 my_insert_使用有问题
bool my_insert_val_tail(struct node *phead, int val)
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return false;
    // 双向链表为空
    if (phead->next == NULL && phead->prev == NULL)
    {
        new_node->data = val;
        new_node->prev = phead;
        new_node->next = NULL;
        phead->next = new_node;

        return true;
    }
    // 双向链表非空
    struct node *pcur;
    for (pcur = phead->next; pcur->next != NULL; pcur = pcur->next)
    {}
    new_node->data = val;
    new_node->prev = pcur;
    new_node->next = NULL;
    pcur->next = new_node;

    return true;
}

// teacher 尾插
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = val;
    pnew->prev = pnew->next = NULL;

    struct node *pcur;
    for (pcur = phead; pcur->next != NULL; pcur = pcur->next)
    {}
    pnew->prev = pcur;
    pcur->next = pnew;
    return true;
}

// my 中间插入
bool my_insert_val_after(struct node *phead, int target, int val)
{
    struct node *new_node = NULL;
    struct node *find = phead;
    struct node *temp = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    // 遍历双向链表
    for (find; find->next != NULL; find = find->next)
    {
        // 是否找到目标
        if ((find->next->data == target) && (find->next->next != NULL))
        {
            // 先断开 find 与 find->next
            // 改变 next
            temp = find->next->next;
            find->next = new_node;
            new_node->next = temp;
            // 改变 prev
            new_node->prev = find;
            temp->prev = new_node; 

            return true;
        }
    }
    // 说明已经到了尾节点
    if (find->data == target)
    {
        return insert_val_tail(find, val);
    }

    printf("遍历完毕, 没有找到目标:\n");
    return false;
}

// teacher 中间插入

bool insert_val_after(struct node *phead, int val, int newval)
{
    struct node * pcur;
    // 遍历链表找到目标值
    for (pcur = phead->next; pcur != NULL && pcur->data != val; pcur = pcur->next)
    {}
    if (!pcur)
        return false;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = newval;
    pnew->prev = pnew->next = NULL;

    // 将新节点的前后链接节点接入
    pnew->prev = pcur;
    pnew->next = pcur->next;

    //!!!
    // 当pcur 到达尾部时 直接将新节点引入
    if (pcur->next != NULL)
    {
        pcur->next->prev = pnew;
        pcur->next = pnew;
    }

    return true;
}

// my 删除元素
bool my_delete_val(struct node *phead, int target)
{
    struct node *find = NULL;
    struct node *temp = NULL;
    struct node *pre = NULL;
    for (pre = phead, find = phead->next; find != NULL; find = find->next, pre = phead->next)
    {
        if (find->next->data == target)
        {
            temp = find->next->next;
            free(find->next);
            find->next = temp;
            temp->prev = find;
            
            return true;
        }
        /*
        else if ((find->next->next->data == target) && (find->next->next->next == NULL))
        {
            free(find->next->next);
            find->next = NULL;
        }
        */
    }

    return false;
}

// teacher 删除节点
bool delete_val(struct node *phead, int val)
{
    struct node *pcur;

    for (pcur = phead->next; pcur != NULL && pcur->data != val; pcur = pcur->next)
    {}
    if (!pcur)
        return false;

    pcur->prev->next = pcur->next;
    if (pcur->next != NULL)
    {
        pcur->next->prev = pcur->prev;
        pcur->prev = pcur->next = NULL;
    }

    free(pcur);

}


// 打印双向链表
void my_print_dlinklist(struct node *phead)
{
    struct node *find = phead->next;
    while (find->next != NULL)
    {
        printf("%d ", find->data);
        find = find->next;
    }
    printf("%d ", find->data);
    putchar('\n');
}

// teacher 打印
void print_dlinklist(struct node *phead)
{
    struct node *pcur;
    for (pcur = phead->next; pcur != NULL; pcur = pcur->next)
    {
        printf("%d ", pcur->data);
    }
    putchar('\n');
}

int main(void)
{
    struct node head;
    init_dlinklist(&head);
    my_insert_val_tail(&head, 10);
    my_insert_val_tail(&head, 20);
    my_insert_val_tail(&head, 30);
    my_insert_val_tail(&head, 40);
    my_insert_val_tail(&head, 50);
    my_print_dlinklist(&head);
    my_insert_val_after(&head, 50, 99);
    printf("After insert after:\n");
    my_print_dlinklist(&head);
    printf("After del\n");
    delete_val(&head, 20);
    my_print_dlinklist(&head);
    printf("Del 99\n");
    delete_val(&head, 99);
    my_print_dlinklist(&head);

    return 0;
}