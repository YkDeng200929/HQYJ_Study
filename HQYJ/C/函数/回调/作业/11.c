#include <stdio.h>

struct student
{
    int id;
    char name[10];
    short score;
};

typedef struct student students;

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

int main()
{

    students stu[3];
    students *stu2 = &stu[1];
    int len = 3;
    intput_student(stu, len);
    output_student(stu, len);
    printf("id:%d\tname:%s\tscore:%hd\n", stu2->id, stu2->name, stu2->score);

    return 0;
}