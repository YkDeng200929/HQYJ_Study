#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 7

typedef struct node
{
    int data;
    struct node *next
} node;

typedef struct linkhashtable
{
    node * linkht[MAX];    
} hashtable;



int main(void)
{
    hashtable htb;

    return 0;
}