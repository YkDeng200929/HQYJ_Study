#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

struct node 
{
    int data;
    struct node *next;
};

struct linkhash
{
    struct node *ht[MAX];
};

void init(struct linkhash *lht)
{
    for (int i = 0; i < MAX; i++)
    {
        lht->ht[i] = NULL;
    }
}

// my insert 
bool insert_hash(struct linkhash *lht, int val)
{
    struct node *pnew = (struct node *)malloc(sizeof(struct node));
    if (!pnew)
    return false;
    // 初始化 pnew
    pnew->data = val;
    pnew->next = NULL;

    int key = val % MAX;
    // 判断位置是否冲突
    while (lht->ht[key] != NULL)
    {
        pnew->next = lht->ht[key];
        lht->ht[key] = pnew;
        return true;
    }
    // 一般情况
    lht->ht[key] = pnew;
    return  true;
}


// my search 
bool search_ht(struct linkhash *lht, int target)
{
    struct node *find = NULL;
    int key = target % MAX;
    for (find = lht->ht[key]->next; find != NULL; find = find->next)
    {
        if (find->data == target)
        {
            printf("In\n");
            return true;
        }
    }
    printf("No in\n");
    return false;
}

// teacher search
bool search_linkhash(struct linkhash *lh, int val)
{
    int key = val % MAX;
    struct node *pcur;
    for (pcur = lh->ht[key]; pcur != NULL; pcur = pcur->next)
    {
        if (pcur->data == val)
        {
            printf("Ok\n");
            return true;
        }
    }
    printf("No in\n");
    return false;
}

// teacher insert
bool insert_linkhash(struct linkhash *lh, int val)
{
    bool ok;
    int key = val % MAX;

    ok = search_linkhash(lh, val);
    if(!ok)
    {
        struct node *pnew = (struct node *)malloc(sizeof(struct node));
        if(!pnew)
        return false;
        pnew->data = val;
        pnew->next = NULL;

        /*优化
        if (lh->ht[key] == NULL)
        {
            lh->ht[key] == pnew;
        }
        else
        {
        */
            pnew->next = lh->ht[key];
            lh->ht[key] = pnew;
        //}
        return true;
    //}
    //else
    //{
    //    return false;   
    //}
}

void print_ht(struct linkhash *lht)
{
    struct node *print = NULL;
    int i;
    for (i = 0; i < MAX; i++)
    {
        print = lht->ht[i];
        // teacher
        // for (print = lht->ht[i]; print != NULL; print = print->next)
        while (print != NULL)
        {
            //print = lht->ht[i];
            printf("%d-->", print->data);
            print = print->next;
        }
        printf("NULL\n");
    }
}

int main(void)
{
    struct linkhash lht;
    init(&lht);
    int arr[MAX] = {10, 11, 22, 13, 24, 7, 14};
    for (int i = 0; i < MAX; i++)
    {
        insert_hash(&lht, arr[i]);
    }
    insert_hash(&lht, 24);
    insert_hash(&lht, 81);
    insert_hash(&lht, 250);
    print_ht(&lht);
    search_ht(&lht, 99);

    return 0;
}