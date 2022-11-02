#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linkhashtable
{
    node * linkht[MAX];    
} hashtable;

void init(hashtable *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        ht->linkht[i] = NULL;
    }
}

bool insert_hashtable(hashtable *ht, int val)
{
    node *pnew = (node *)malloc(sizeof(node));
    if (!pnew)
    return false;
    pnew->data = val;
    int key = val % MAX;
    pnew->next = ht->linkht[key];
    ht->linkht[key] = pnew;
    return true;
}

void print(hashtable *ht)
{
    int i;
    node *print = NULL;
    for (i = 0; i < MAX; i++)
    {
        for (print = ht->linkht[i]; print != NULL; print = print->next)
        {
            printf("%d-->", print->data);
        }
        printf("NULL\n");
    }
}

int main(void)
{
    hashtable htb;
    init(&htb);
    insert_hashtable(&htb, 10);
    insert_hashtable(&htb, 24);
    insert_hashtable(&htb, 30);
    print(&htb);

    return 0;
}