#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 7

struct hashtable
{
    int data[MAX];
    int length;
};

// my init
void my_init_hashtable(struct hashtable *hs)
{
    //memset(hs->data, -1, sizeof(hs->data));    
    //memset是按字节来改变值, 1 int = [0 0 0 0] --> [-1 -1 -1 -1]
    for (int i = 0; i < MAX; i++)
    {
        hs->data[i] = -1;
    }
    hs->length = 0;
}

// my insert hash table
bool my_insert(struct hashtable *ht, int *arr)
{
    int i = 0, index = 0;
    for (i; i < MAX; i++)
    {
        index = arr[i] % MAX;
        while (ht->data[index] != -1)
        {
            printf("ok\n");
            index = (index + 1) % MAX;
        }
        ht->data[index] = arr[i];
        ht->length++;
    }
}

// teacher insert hash table
bool insert_hashtable(struct hashtable *ht, int val)
{
    int key = val % MAX;
    while (ht->data[key] != -1)
    {
        key = (key + 1) % MAX;
    }
    ht->data[key] = val;
    ht->length++;
    return true;
}

// my search hash table
bool my_search_hashtable(struct hashtable *ht, int val)
{
    int key = val % MAX, count = 0;
    if (ht->data[key] == val)
    {
        printf("%d In\n", val);
        return true;
    }
    else
    {
        while (count < ht->length)
        {
            key = (key + 1) % MAX;
            if (ht->data[key] == val)
            {
                printf("%d In\n", val);
                return true;
            }
            count++;
        }
        printf("%d No in\n", val);
        return false;
    }
}

// teacher search hash table
bool search_hashtable(struct hashtable *ht, int val)
{
    // 如果哈希表为空, 则退出
    if (ht->length == 0)
    return false;
    int key = val % MAX;
    while (ht->data[key] != val)
    {
        key = (key + 1) % MAX;
        if (key == val % MAX && ht->data[key] == -1)
        {
            printf("%d No in\n", val);
            return false;
        }
    }
    printf("%d In\n", val);
    return true;
}

void print(struct hashtable *ht)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", ht->data[i]);
    }
    putchar('\n');
}

int main(void)
{
    int arr[MAX] = {10, 11, 22, 13, 24, 7, 14};
    struct hashtable htab;
    my_init_hashtable(&htab);
    //my_insert(&htab, arr);
    for (int i = 0; i < MAX; i++)
    {
        insert_hashtable(&htab, arr[i]);
    }
    print(&htab);
    my_search_hashtable(&htab, 24);
    my_search_hashtable(&htab, 10);
    my_search_hashtable(&htab, 99);

    return 0;
}