#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void init(node *head)
{
    head->data = 0;
    head->next = NULL;
}

bool insert_val_head(node *head, int val)
{
    node *pnew = (node *)malloc(sizeof(node));
    if (!pnew)
    return false;
    pnew->data = val;
    pnew->next = head->next;
    head->next = pnew;
    return true;
}

void creat_link1(node *link1)
{
    int arr[] = {9, 7, 5, 3, 1};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        insert_val_head(link1, arr[i]);
    }
}

void creat_link2(node *link2)
{
    int arr[] = {10, 8, 6, 4, 2};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        insert_val_head(link2, arr[i]);
    }
}

node * combine_link(node *link1, node *link2)
{
    node *find = link1;
    for (find; find->next != NULL; find = find->next)
    {}
    find->next = link2->next;
    return link1;
}

node * bubble_sort(node  *head)
{
    int i, j, num = 0;
    node * prev = NULL, * target = NULL, *temp = NULL;
    for (temp = head->next; temp != NULL; temp = temp->next, num++)
    {}
    for (i = 0; i < num; i++)
    {
        for (prev = head, target = prev->next, j = 0; j < num - i - 1; j++, prev = prev->next, target = prev->next)
        {
            if (target->data > target->next->data)
            {
                prev->next = target->next;
                target->next = prev->next->next;
                prev->next->next = target;
            }
        }
    }
    return NULL;
}

void print_link(node *head)
{
    node *print = head;
    for (print = head->next; print != NULL; print = print->next)
    {
        printf("%d ", print->data);
    }
    putchar('\n');
}

int main(void)
{
    node linklist1;
    node linklist2;
    init(&linklist1);
    creat_link1(&linklist1);
    print_link(&linklist1);
    init(&linklist2);
    creat_link2(&linklist2);
    print_link(&linklist2);
    node *combin = NULL;
    combin = combine_link(&linklist1, &linklist2);
    print_link(combin);
    bubble_sort(combin);
    print_link(combin);

    return 0;
}