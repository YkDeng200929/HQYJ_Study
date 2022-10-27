#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 5

struct seqlist
{
    int length;
    int data[MAX];
};

// 初始化
void init_seq(struct seqlist *seq)
{
    memset(seq, 0, sizeof(struct seqlist));
}

// 增
//      按位置插入 
bool insert_data(struct seqlist *seq, int pos, int val)
{
    // 如果顺序表为空表
    if (seq->length == 0)
    {
        if (pos <= 0)
            return false;
        seq->data[pos-1] = val;
        seq->length++;
        return true;
    }
    else
    {
        if (pos < 0 || pos >= seq->length)
        seq->data[pos-1] = val;
        seq->length++;
        return true;
    }
}

//      在中间插入
bool insert_in_middle(struct seqlist *seq, int pos, int val)
{
    if (pos <= 0 || pos >= seq->length)
        return false;
    int i;
    for (i = seq->length; i > pos-1; i--)
    {
        int temp;
        temp = seq->data[i];
        seq->data[i] = seq->data[i-1];
        seq->data[i-1] = temp;
    }
    seq->data[pos-1] = val;
    seq->length++;
    return true; 
}

// 删
bool del_ele(struct seqlist *seq, int pos)
{
    int i;
    if (pos < 0 || pos > seq->length)
        return false;
    for (i = 0; i < pos-1; i++)
    {
    }
    for (; i < seq->length; i++)
    {
        seq->data[i] = seq->data[i+1];
    }
    seq->length--;
    return true;
}

// 改

// 查
void print_seq(struct seqlist *seq)
{
    int i;
    for (i = 0; i < seq->length; i++)
    {
        printf("%d ", seq->data[i]);
    }
    putchar('\n');
}

// 打印

int main()
{
    struct seqlist seq;
    init_seq(&seq);
    insert_data(&seq, 1, 10);
    insert_data(&seq, 2, 20);
    insert_data(&seq, 3, 30);
    insert_data(&seq, 4, 40);
    insert_data(&seq, 5, 50);
    print_seq(&seq);
    insert_in_middle(&seq, 2, 99);
    print_seq(&seq);
    del_ele(&seq, 2);
    print_seq(&seq);

    return 0;
}