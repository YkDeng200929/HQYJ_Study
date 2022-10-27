#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// 初始化
void init_link(struct node *head)
{
    head->data = 0;
    head->next = NULL;
    printf("初始化结束\n");
}
// 增
bool insert_ele(struct node *head, int target, int val)
{
    // 如果链表为空
    struct node *new_data = NULL, *find = NULL;
    new_data = (struct node *)malloc(sizeof(struct node));
    if (!new_data)
    {
        printf("Malloc error!\n");
        return false;
    }
    if (!head->next)
    {
        printf("链表为空:\n");
        head->next = new_data;
        new_data->data = val;
        new_data->next = NULL;
        return true;
    }
    // 如果链表非空
    else
    {
        printf("链表非空:\n");
        for (find = head->next; find; find = find->next)
        {
            if (find->data == target)
            {
                find->next = new_data;
                new_data->next = find->next->next;
                return true;
            }
        }
    }
}
// 删
// 改
// 查
void print_link(struct node *head)
{
    struct node *print = NULL;
    // 因为无需打印头, 所以print = head->next
    for (print = head->next; print; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    printf("正在初始化\n");
    init_link(head);    
    printf("初始化完成\n");
    insert_ele(head, 1, 5);
    print_link(head);
    insert_ele(head, 2, 20);
    insert_ele(head, 3, 30);
    insert_ele(head, 4, 40);
    print_link(head);

    return 0;
}