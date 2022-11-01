#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// ��ʼ��
void init_link(struct node *head)
{
    head->data = 0;
    head->next = NULL;
    printf("��ʼ������\n");
}
// ��
bool insert_ele(struct node *head, int target, int val)
{
    // �������Ϊ��
    struct node *new_data = NULL, *find = NULL;
    new_data = (struct node *)malloc(sizeof(struct node));
    if (!new_data)
    {
        printf("Malloc error!\n");
        return false;
    }
    if (!head->next)
    {
        printf("����Ϊ��:\n");
        head->next = new_data;
        new_data->data = val;
        new_data->next = NULL;
        return true;
    }
    // �������ǿ�
    else
    {
        printf("����ǿ�:\n");
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
// ɾ
// ��
// ��
void print_link(struct node *head)
{
    struct node *print = NULL;
    // ��Ϊ�����ӡͷ, ����print = head->next
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
    printf("���ڳ�ʼ��\n");
    init_link(head);    
    printf("��ʼ�����\n");
    insert_ele(head, 1, 5);
    print_link(head);
    insert_ele(head, 2, 20);
    insert_ele(head, 3, 30);
    insert_ele(head, 4, 40);
    print_link(head);

    return 0;
}