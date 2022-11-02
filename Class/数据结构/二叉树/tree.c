#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

void init(struct btree *tr)
{
    tr->data = 0;
    tr->left = NULL;
    tr->right = NULL;
}

bool insert(struct btree *tr, int val, int dir)
{
    struct btree *newtr = (struct btree *)malloc(sizeof(struct bree));
    if (!newtr)
        return false;
    newtr->data = val;
    newtr->left = NULL;
    newtr->right = NULL;
    if (dir == 0 && tr->left == NULL)
    {
        tr->left = newtr;
        return true
    }
    else if (dir == 1 && tr->right == NULL)
    {
        tr->right = newtr;
        return true;
    }
    return false;
}
/*
bool new_insert(struct btree *tr, int val)
{
    struct btree *newtr = (struct btree *)malloc(sizeof(struct btree));
    if (!newtr)
    return false;
    newtr->data = val;
    newtr->left = NULL;
    newtr->right = NULL;
    if ()

    if (tr->left == NULL)
    {
        tr->left = newtr;
        return true;
    }
    if (tr->right == NULL)
    {
        tr->right = newtr;
        return true;
    }
}
*/

bool recurse(struct btree **btr)
{
}

int main(void)
{
    struct btree tree;
    my_init(tree);
    int i, val, dir;
    for (i = 0; i < 6; i++)
    {
        printf("Enter val, dir\n");
        scanf("%d %d", &val, &dir);
        insert(&tree, val, dir);
    }

    return 0;
}