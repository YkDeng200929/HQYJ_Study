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
}

bool insert(struct hashtable *ht)
{}

int main(void)
{
    struct hashtable hst;
    init(&hst);

    return 0;
}