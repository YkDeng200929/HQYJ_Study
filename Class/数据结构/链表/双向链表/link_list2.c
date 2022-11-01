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

// ��ʼ��
void init_dlinklist(struct node *phead)
{
    phead->data = 0;
//  [ phead ]  --> [ phead->next ](prev) --> [  ]
    
    phead->prev = phead->next = NULL;
}

// my ����Ԫ��(β��) :: ��� my_insert_ʹ��������
bool my_insert_val_tail(struct node *phead, int val)
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return false;
    // ˫������Ϊ��
    if (phead->next == NULL && phead->prev == NULL)
    {
        new_node->data = val;
        new_node->prev = phead;
        new_node->next = NULL;
        phead->next = new_node;

        return true;
    }
    // ˫������ǿ�
    struct node *pcur;
    for (pcur = phead->next; pcur->next != NULL; pcur = pcur->next)
    {}
    new_node->data = val;
    new_node->prev = pcur;
    new_node->next = NULL;
    pcur->next = new_node;

    return true;
}

// teacher β��
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

// my �м����
bool my_insert_val_after(struct node *phead, int target, int val)
{
    struct node *new_node = NULL;
    struct node *find = phead;
    struct node *temp = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    // ����˫������
    for (find; find->next != NULL; find = find->next)
    {
        // �Ƿ��ҵ�Ŀ��
        if ((find->next->data == target) && (find->next->next != NULL))
        {
            // �ȶϿ� find �� find->next
            // �ı� next
            temp = find->next->next;
            find->next = new_node;
            new_node->next = temp;
            // �ı� prev
            new_node->prev = find;
            temp->prev = new_node; 

            return true;
        }
    }
    // ˵���Ѿ�����β�ڵ�
    if (find->data == target)
    {
        return insert_val_tail(find, val);
    }

    printf("�������, û���ҵ�Ŀ��:\n");
    return false;
}

// teacher �м����

bool insert_val_after(struct node *phead, int val, int newval)
{
    struct node * pcur;
    // ���������ҵ�Ŀ��ֵ
    for (pcur = phead->next; pcur != NULL && pcur->data != val; pcur = pcur->next)
    {}
    if (!pcur)
        return false;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = newval;
    pnew->prev = pnew->next = NULL;

    // ���½ڵ��ǰ�����ӽڵ����
    pnew->prev = pcur;
    pnew->next = pcur->next;

    //!!!
    // ��pcur ����β��ʱ ֱ�ӽ��½ڵ�����
    if (pcur->next != NULL)
    {
        pcur->next->prev = pnew;
        pcur->next = pnew;
    }

    return true;
}

// my ɾ��Ԫ��
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

// teacher ɾ���ڵ�
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


// ��ӡ˫������
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

// teacher ��ӡ
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