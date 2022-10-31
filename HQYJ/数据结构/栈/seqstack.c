#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *top;
    struct node *below;
};

struct node * init(struct node *ele);
void insert(struct node *ele);

int main(void)
{
    struct node *ele = NULL;
    ele = init(ele);    

    return 0;
}

struct node * init(struct node *ele)
{
    ele = (struct node *)malloc(sizeof(struct node));
    if(!ele)
    {
        printf("Malloc error\n");
        return NULL;
    }
    return ele;
}