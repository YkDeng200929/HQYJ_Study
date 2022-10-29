#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char * s_gets(char *st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue; // 处理剩余输入行
    }
}


int main()
{
    struct film * head = NULL; // 头节点
    struct film * prev, *current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_get(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        // 如果链表为空
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop)");
        prev = current;

    }


    return 0;
}