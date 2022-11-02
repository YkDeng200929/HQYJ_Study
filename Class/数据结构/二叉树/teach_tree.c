#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

int func(int val)
{
    if (val == 0 || val == 1)
    return 1;
    else
    return val*func(val - 1);
}

void creat_btree(struct btree **tr)
{
    int input_num;
    scanf("%d", &input_num);
    if (input_num == -1)
    {
        *tr = NULL;
        return ;
    }
    else
    {
        *tr = (struct btree *)malloc(sizeof(struct btree));
        (*tr)->data = input_num;
        (*tr)->left = (*tr)->right = NULL;
        creat_btree(&((*tr)->left));
        creat_btree(&((*tr)->right));
        return ;
    }
}

void preorder(struct btree *t)
{
    if (t == NULL)
    return ;
    else
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

// void inorder
void midorder(struct btree *t)
{
    if (t == NULL)
    return ;
    else
    {
        midorder(t->left);
        printf("%d ", t->data);
        midorder(t->right);
    }
}


void afterorder(struct btree *t)
{
    if (t == NULL)
    return  ;
    else
    {
        afterorder(t->left);
        afterorder(t->right);
        printf("%d ", t->data);
    }
}

// error
int get_high(struct btree *t)
{
    static int high = 0, judge = 0;
    if (t == NULL)
    return high;
    high++;
    get_high(t->left);
}

int get_height(struct btree *t)
{
    int lh = 0, rh = 0;
    if (t == NULL)
    return 0;
    else
    {
        lh = get_height(t->left);
        rh = get_height(t->right);
        return (lh > rh) ? (lh + 1) : (rh + 1);
    }
}

int main(void)
{
    struct btree *btr;
    creat_btree(&btr);
    preorder(btr);
    putchar('\n');
    midorder(btr);
    putchar('\n');
    afterorder(btr);
    get_high(btr);
    putchar('\n');
    printf("high: %d\n", get_height(btr));

    return 0;
}