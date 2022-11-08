#include <stdio.h>
#define MAX_STU 5

typedef struct students
{
    int id;
    char name[10];
    short score;
} students;

//typedef struct student students;

void intput_student(students *stu, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("Enter id: ");
        scanf("%d", &stu[i].id);
        printf("Enter name: ");
        scanf("%s", stu[i].name);
        printf("Enter score: ");
        scanf("%hd", &stu[i].score);
    }
}

void output_student(students *stu, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("id: %d\n", stu[i].id);
        printf("name: %s\n", stu[i].name);
        printf("score: %hd\n", stu[i].score);
    }
}

void get_class_stu(students class[][MAX_STU], int class_num)
{
    int i;
    for (i = 0; i < class_num; i++)
    {
        for (int j = 0; j < MAX_STU; j++)
        {
            printf("Enter id: ");
            scanf("%d", &class[i][j].id);
            printf("Enter name: ");
            scanf("%s", class[i][j].name);
            printf("Enter score: ");
            scanf("%hd", &class[i][j].score);
        }
    }
}

void get_class_info(students class[][MAX_STU], int class_num)
{
    for (int i = 0; i < class_num; i++)
    {
        printf("Class: %d\n", i+1);
        for (int j = 0; j < MAX_STU; j++)
        {
            printf("ID: %d Name: %s Score: %d\n", class[i][j].id, class[i][j].name, class[i][j].score);
        }
    }
}

int main()
{

    //students stu[3];
    //students *stu2 = &stu[1];
    //int len = 3;
    //intput_student(stu, len);
    //output_student(stu, len);
    //printf("id:%d\tname:%s\tscore:%hd\n", stu2->id, stu2->name, stu2->score);
    students class[5][MAX_STU];
    get_class_stu(class, 5);
    get_class_info(class, 5);

    return 0;
}