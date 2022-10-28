#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

// ��ʼ������ (ͷ�ڵ�)
void init_linklist(struct node *phead)
{
    phead->data = 0;
    phead->next = NULL;
}

// my ����Ԫ��
bool my_insert_ele(struct node *phead, int val)
{
    struct node *new_data = NULL;
    new_data = (struct node *)malloc(sizeof(struct node));
    if (!new_data)
        return false;
    new_data->data = val;
    new_data->next = NULL;

    struct node *temp;
    for (temp = phead; temp->next != NULL; temp = temp->next)
    {
    }
    temp->next = new_data;    

    return true;
}

// teacher ����Ԫ�� β��
bool insert_val_tail(struct node *phead, int val)
{
    // �½�һ��Ԫ��
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (pnew == NULL)// if (!pnew)
        return false;
    pnew->data = val;
    pnew->next = NULL;

    struct node *pcur;
    // Ѱ�����һ��Ԫ��
    for (pcur = phead; pcur->next != NULL; pcur = pcur->next )
    {
    }
    pcur->next = pnew;
    return true;
}

// my �м����Ԫ��
bool insert_in_middle(struct node *phead, int target, int val)
{
    struct node *new_val, *temp, *pcur;
    new_val = (struct node *)malloc(sizeof(struct node));
    if (!new_val)
        return false;
    // pcur����Ѱ�ҵ� target ������ , ����ҵ� target, �� pcur ��Ϊͷ
    for (pcur = phead; pcur->data != target; pcur = pcur->next)
    {}// �ѵ���Ŀ��ֵ
    if (!pcur)
    {
        pcur->next = new_val;
        new_val->next = NULL;
        return true;
    }
    else
    {
        new_val->data = val;
        // ���ڴ洢Ŀ��ֵ��һ��Ԫ�صĵ�ַ
        temp = pcur->next;
        pcur->next = new_val;
        new_val->next = temp;
    return true;
    }
}

// teacher ���м����
bool insert_val_after(struct node *phead, int val, int newval)
{
    struct node *pcur;

    for (pcur = phead->next; pcur != NULL && pcur->data != val; pcur = pcur->next)
    {
    }
    if (!pcur)
        return false;
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
        return false;
    pnew->data = newval;
    pnew->next = NULL;

    pnew->next = pcur->next;
    pcur->next = pnew;
}

// my ɾ���ڵ�
bool del_node(struct node *phead, int target)
{
    bool judge = false;
    struct node *pcur, *temp;
    // Ѱ��target
    for (pcur = phead->next ; pcur->next != NULL;)
    {
        if (pcur->next->data == target)
        {
            judge = true;
            break;
        }
        else
        {
            pcur = pcur->next;
            judge = false;
        }
    }
    // temp ��� target ���¸�Ԫ�صĵ�ַ
    temp = pcur->next->next;
    free(pcur->next);
    pcur->next = temp;
    return judge;
}

// teacher ɾ���ڵ�
bool delete_val(struct node *phead, int val)
{
    struct node *prev, *pdel;

    for (prev = phead, pdel = phead->next; pdel != NULL && pdel->data != val; prev = pdel, pdel = pdel->next)
    {
    }
    if (!pdel)
        return false;
    
    prev->next = pdel->next;
    pdel->next = NULL;
    free(pdel);
    pdel = NULL;

    return true;
}

// my_��������
bool my_reverse(struct node *phead)
{
    struct node *prev = NULL, *after = NULL;
    int count = 0;
    // ð�����򽻻�ֵ
    for (prev = phead->next; prev != NULL; prev = prev->next)
    {
        for (after = phead->next; after->next != NULL; after = after->next)
        {   
            if (after->data < after->next->data)
            {
                int temp;
                temp = after->data;
                after->data = after->next->data;
                after->next->data = temp;
            }
        }
    }
}

// teacher ��������
void reverse_linklist(struct node *phead)
{
    struct node *pbefore = phead;
    struct node *pcur = phead->next;
    struct node *pafter;

    // û��ͷ�ڵ�ֱ�������δ���
    if (phead->next == NULL)
        return ;
    
    // �ж�����Ϊ pcur
    while (pcur != NULL)
    {
        pafter = pcur->next;
        pcur->next = pbefore;
        pbefore = pcur;
        pcur = pafter;
    }
    phead->next->next = NULL;
    phead->next = pbefore;
    return ;
}

// ��ӡ���� 
void print_link_list(struct node *phead)
{
    /*
    struct node *temp = phead;
    while (temp->next)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    */
    struct node *pcur;
    for (pcur = phead->next; pcur != NULL; pcur = pcur->next)
    {
        printf("%d--->", pcur->data);
    }
    putchar('\n');
}

int main(void)
{
    struct node head;
    init_linklist(&head);
    insert_val_tail(&head, 3);
    insert_val_tail(&head, 5);
    insert_val_tail(&head, 7);
    insert_val_tail(&head, 9);

    //print_link_list(&head);
    //insert_in_middle(&head, 7, 1);
    //print_link_list(&head);
    //del_node(&head, 7);
    print_link_list(&head);
    printf("������\n");
    //reverse(&head);
    new_reverse(&head);
    printf("�������\n");
    print_link_list(&head);
    reverse_linklist(&head);
    print_link_list(&head);

    return 0;
}