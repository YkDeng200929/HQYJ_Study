#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 7

struct hashtable
{
    int htab[MAX];
    int length;
};

void init(struct hashtable *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        ht->htab[i] = -1;
    }
    ht->length = 0;
}

bool insert_hashtable(struct hashtable *ht, int val)
{
    if (ht->length == MAX)
    return false;
    int key = val % MAX;
    while (ht->htab[key] != -1)
    {
        key = (key + 1) % MAX;
    }
    ht->htab[key] = val;
    ht->length++;
    return true;
}

void print(struct hashtable *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\n", ht->htab[i]);
    }
}

int main(void)
{
    struct hashtable hst;
    init(&hst);
    insert_hashtable(&hst, 10);
    insert_hashtable(&hst, 30);
    insert_hashtable(&hst, 24);
    print(&hst);

    return 0;
}