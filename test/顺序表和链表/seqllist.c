#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 5

struct seqlist
{
    int data[MAX];
    int length;
};

void init(struct seqlist *s)
{
    memset(s->data, 0, sizeof(s->data));
    s->length = 0;
}


// 尾插
bool insert_val_tail(struct seqlist *s, int val)
{
    if (s->length == MAX)
    return false;
    s->data[s->length] = val;
    s->length++;
    return true;
}

// 删除元素
bool del_val(struct seqlist *s, int target)
{
    if (s->length == 0)
    return false;
    int i = 0;
    for (i = 0; i < s->length; i++)
    {
        if (s->data[i] == target)
        break;
    }
    for (i; i < MAX; i++)
    {
        s->data[i] = s->data[i+1];
    }
    s->data[i+1] = '\0';
    s->length--;
    return true;
}

// 目标值尾部插入元素
bool insert_val_after(struct seqlist *s, int target, int val)
{
    if (s->length == MAX)
    return false;
    int i, j;
    for (i = MAX - 1; s->data[i] != target; i--)
    {
        if (i < 0)
        return false;
    }
    for (j = MAX - 1; j > i; j--)
    {
        s->data[j] = s->data[j-1];
        s->length++;
    }
    s->data[j+1] = val;
    return true;
}

// 打印顺序表
void print_seq(struct seqlist *s)
{
    for (int i = 0; i < s->length; i++)
    {
        printf("%d ", s->data[i]);
    }
    putchar('\n');
}

int main(void)
{
    struct seqlist seq;
    insert_val_tail(&seq, 10);
    insert_val_tail(&seq, 20);
    insert_val_tail(&seq, 30);
    insert_val_tail(&seq, 40);
    insert_val_tail(&seq, 50);
    printf("%d\n", seq.length);
    del_val(&seq, 20);
    print_seq(&seq);
    printf("Insert\n");
    insert_val_after(&seq, 30, 99);
    printf("ok");
    print_seq(&seq);

    return 0;
}