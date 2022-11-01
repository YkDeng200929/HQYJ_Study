#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 2

typedef struct student
{
    char name[20];
    int score;
    int id;
} student;

typedef struct class
{
    int class_num;
    student stus[MAX];
} class;

// 初始化
void init(class *cls)
{
    memset(cls, 0, sizeof(struct class));
}

// 插入学生
bool insert_stu(class *cls, int len)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        (cls+i)->class_num = i+1;
        printf("class num: %d\n", i+1);
        for (j = 0; j < MAX; j++)
        {
            getchar();
            printf("please enter id: ");
            scanf("%d", &cls[i].stus[j].id);
            printf("please enter name: ");
            getchar();
            scanf("%s", cls[i].stus[j].name);
            getchar();
            printf("please enter score: ");
            getchar();
            scanf("%d", &cls[i].stus[j].score);
        }
    }
    return true;
}

// 查询所有学生信息
void print_info(class *datas, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Class : %d\n", i+1);
        for (int j = 0; j < MAX; j++)
        {
            printf("Name: %s Score: %d", datas[i].stus[j].name, datas[i].stus[j].score);
        }
        putchar('\n');
    }
}

// 删除学生信息
bool del_stu(class *datas, int cls_num, int id)
{
    int i;
    for (i = 0; datas[cls_num-1].stus[i].id != id; i++)
    {}
    memset(&(datas[cls_num-1].stus[i]), 0, sizeof(student));
    return true;
}

int main()
{
    class datas[2];
    int len = 2;
    insert_stu(datas, len);
    print_info(datas, len);
    del_stu(datas, 2, 2);
    print_info(datas, len);

    return 0;
}