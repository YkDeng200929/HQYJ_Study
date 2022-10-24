#include <stdio.h>

struct student
{
    int id;
    char name[10];
    short score;
};

void intput_student(struct student *stu)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("Enter id: ");
        scanf("%d", &stu[i].id);
        printf("Enter name: ");
        scanf("%s", stu[i].name);
        printf("Enter score: ");
        scanf("%hd", stu[i].score);
    }
}

void output_student(struct student *stu)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("id: %d\n", stu[i].id);
        printf("name: %s\n", stu[i].name);
        printf("score: %hd\n", stu[i].score);
    }
}

int main()
{

    struct student students[3];
    intput_student(students);
    output_student(students);

    return 0;
}