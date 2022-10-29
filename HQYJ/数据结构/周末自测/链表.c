#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// init
void init(struct node *phead)
{
    phead->data = 0;
    phead->next = NULL;
    printf("初始化完毕");
}

// 增
void insert_data(struct node *node)
{}

// 删

// 改

// cha

int main()
{
    struct node *head = NULL;
    init(head);


    return 0;
}