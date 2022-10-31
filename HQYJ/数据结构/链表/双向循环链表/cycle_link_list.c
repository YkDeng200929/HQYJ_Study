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

// ��ʼ��
void init_clinklist(struct node *phead)
{
    phead->data = 0;
    phead->prev = phead->next = phead;
    return ;
}

// my β��
bool my_insert_val_tail(struct node *phead, int val)
{
    struct node *new_node, *find;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return false;
    new_node->data = val;

    // �������Ϊ��
    if (phead->next == phead)
    {
        new_node->next = phead;
        new_node->prev = phead;
        phead->next = new_node;
        phead->prev = new_node;
        return true;
    }
    // �������ǿ�
    for (find = phead; find != phead->prev; find = find->next)
    {}
    find->next->prev = new_node;
    find->next = new_node;
    new_node->prev = find;
    new_node->next = find->next;
}

// teacher β��
bool insert_val_tail(struct node *phead, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    // ��ʼ���½ڵ�
    pnew->data = val;
    pnew->prev = pnew->next = pnew;

    // ���½ڵ��ͷָ�� phead ��ǰһ���ڵ�λ��
    pnew->prev = phead->prev;
    // ���½ڵ��βָ�� phead 
    pnew->next = phead;
    // ����½ڵ�ͷβ�Ĳ���

    // phead ǰһ���ڵ��β���� pnew
    phead->prev->next = pnew;
    // phead ��ͷָ�� pnew
    phead->prev = pnew;

    return true;
}

// my ��Ԫ�ص�β������
bool my_insert_val_after(struct node *phead, int target, int val)
{
    // �����½ڵ�
    struct node *new_node = NULL;
    struct node *pcur;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
        return false;
    // ��ʼ���½ڵ�
    new_node->data = val;
    new_node->prev = new_node->next = new_node;

    // �ҵ�Ŀ��ֵ
    // 1���������� ֱ��ͷ
    for (pcur = phead->next; pcur != phead && pcur->data != target; pcur = pcur->next)
    {}
    // 2���ж��Ƿ��ҵ�Ŀ��ֵ
    if (pcur == phead)
        return false;// δ�ҵ�Ŀ��ֵ
    // ���ҵ�Ŀ��ֵ, �����
    // ���½ڵ�� next ָ�� pcur
    //new_node->next = pcur;
    new_node->next = pcur->next;
    // ���½ڵ�� prev ָ�� pcur->prev
    //new_node->prev = pcur->prev;
    new_node->prev = pcur;
    // �� pcur �� prev ָ�� new_node
    //pcur->prev = new_node;
    pcur->next->prev = new_node;
    // �� pcur->prev �� next ָ�� new_node
    pcur->next = new_node;

    return true;
}

// teacher ���м����

bool insert_val_after(struct node *phead, int val, int newval)
{
    struct node *pcur;

    for (pcur = phead->next; pcur != phead && pcur->data != val; pcur = pcur->next)
    {}
    if (pcur == phead)
        return false;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));

    //��ʼ��pnew
    pnew->data = newval;
    pnew->prev = pnew->next = pnew;

    pnew->prev = pcur;
    pnew->next = pcur->next;

    pcur->next->prev = pnew;
    pcur->next = pnew;

    return true;
}

// my ɾ���ڵ�
bool my_delete_val(struct node *phead, int target)
{
    // ���� phead, �ҵ� target
    struct node *pcur = NULL;
    for (pcur = phead->next; pcur != phead && pcur->data != target; pcur = pcur->next)
    {}
    if (pcur == phead)
        return false;
    // ��ʱ��ʾ pcur->data == target, Ӧ�ͷ� pcur
    // pcur ǰ�ýڵ� �� next Ӧָ�� pcur ����һ���ڵ�
    //pcur->next = pcur->next->next;
    pcur->prev->next = pcur->next;
    // pcur ����һ���ڵ�� prev Ӧָ�� pcur ��ǰһ���ڵ�
    pcur->next->prev = pcur->prev;

    // �Ѿ���λ����
    pcur->next = pcur->prev = NULL;
    free(pcur);
}

// teacher ɾ���ڵ�
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
    printf("�����\n");
    print_clinklist(&head);
    //delete_val(&head, 40);
    my_delete_val(&head, 20);
    printf("ɾ����\n");
    print_clinklist(&head);

    return 0;
}