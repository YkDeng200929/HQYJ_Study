#include <stdio.h>

struct student
{
    int id;
    char name[10];
    short score;
};

void intput_student(struct student *stu, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("Enter id: ");
        scanf("%d", &stu[i].id);
        printf("Enter name: ");
        scanf("%s", stu[i].name);
        printf("Enter score: ");
        scanf("%hd", stu[i].score);
    }
}

void output_student(struct student *stu, int len)
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

    struct student students[3];
    int len = 3;
    intput_student(students, len);
    output_student(students, len);

    return 0;
}