#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3       // 每个班的最大人数

typedef struct
{
    char name[16];
    int id;
    int score;
    int age;
} Stu;

typedef struct
{
    Stu stu_info[MAX];       // 学生信息
    int n;                   // 记录当前学生人数
} Class;


// init_classroom   初始化班级信息
void init_classroom(Class *class, int class_num)
{
    memset(class, 0, sizeof(Class)*class_num);
}

// input_student    输入单个学生信息
// 参数: class_num 表示 班级号, stu_id 表示学生学号
void input_student(Class *class, int class_num, int stu_id)
{
    printf("Enter name: ");
    scanf("%s", (class+class_num)->stu_info[stu_id].name);
    printf("Enter id: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id].id);
    printf("Enter score: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id].score);
    printf("Enter age: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id].age);
}

// output_student   输出单个学生信息
// 参数: class_num 表示 班级号
void output_student(Class *class, int class_num, int stu_id)
{
    printf("Name: %s, Id: %d, Score: %d, Age: %d\n",
    (class+class_num)->stu_info[stu_id].name,
    (class+class_num)->stu_info[stu_id].id,
    (class+class_num)->stu_info[stu_id].score,
    (class+class_num)->stu_info[stu_id].age
    );
}

// input_classroom  给班级统一赋值
// 参数: num_class 表示 班级数
void input_classroom(Class *class, int num_class)
{
    for (int i = 0; i < num_class; i++)
    {
        printf("Class: %d\n", i+1);
        for (int j = 0; j < MAX; j++)
        {
            printf("Enter name: ");
            scanf("%s", (class+i)->stu_info[j].name);
            printf("Enter id: ");
            scanf("%d", &(class+i)->stu_info[j].id);
            printf("Enter score: ");
            scanf("%d", &(class+i)->stu_info[j].score);
            printf("Enter age: ");
            scanf("%d", &(class+i)->stu_info[j].age);
        }
    }
}

// output_classroom 输出班级中所有学生信息
void output_classroom(Class *class, int num_class)
{
    for (int i = 0; i < num_class; i++)
    {
        printf("Class: %d\n", i+1);
        for (int j = 0; j < MAX; j++)
        {
            printf("Name: %s, Id: %d, Score: %d, Age: %d",
            (class+i)->stu_info[j].name,
            (class+i)->stu_info[j].id,
            (class+i)->stu_info[j].score,
            (class+i)->stu_info[j].age
            );
        }
        putchar('\n');
    }
}

// 删除学生信息
void delete_info(Class *class, int class_num, int stu_id)
{
    memset(&((class+class_num)->stu_info[stu_id]), 0, sizeof(Stu));
}

// 修改学生信息
void modify_info(Class *class, int class_num, int stu_id)
{
    printf("Modify name: ");
    scanf("%s", (class+class_num)->stu_info[stu_id].name);
    printf("Modify id: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id].id);
    printf("Modify score: ");
    scanf("%d", (class+class_num)->stu_info[stu_id].score);
    printf("Modify age: ");
    scanf("%d", (class+class_num)->stu_info[stu_id].age);
}

// 学生分数由低到高排序
void sort_info(Class *class, int class_num)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - i - 1; j++)
        {
            Stu temp;
            if ((class+class_num)->stu_info[j].score > (class+class_num)->stu_info[j+1].score)
            {
                temp = (class+class_num)->stu_info[j];
                (class+class_num)->stu_info[j] = (class+class_num)->stu_info[j+1];
                (class+class_num)->stu_info[j+1] = temp;
            }
        }
    }
}

// show_menu
void show_menu(Class *class, int num_class)
{
    int selection, stu_id, class_num;
    
    do
    {
        printf("<1>插入学生到班级\n");
        printf("<2>删除学生到班级\n");
        printf("<3>修改学生信息\n");
        printf("<4>输出所有班级内的学生信息\n");
        printf("<5>让班级内的学生分数从低到高排序\n");
        printf("<6>关闭学生系统\n");
        printf("Enter: ");
        scanf("%d", &selection);
        switch (selection)
        {
            case 1: 
            {
                printf("Enter info------------------\n");
                //printf("Enter stu_id and class_num: ");
                //scanf("%d %d", &stu_id, &class_num);
                input_classroom(class, num_class);
                break;
            }
            case 2:
            {
                printf("Delete info-----------------\n");
                printf("Enter stu_id and class_num: ");
                scanf("%d %d", &stu_id, &class_num);
                delete_info(class, class_num, stu_id);
                break;
            }
            case 3:
            {
                printf("Modify info------------------\n");
                printf("Enter stu_id and class_num: ");
                scanf("%d %d", &stu_id, &class_num);
                modify_info(class, class_num, stu_id);
                break;
            }
            case 4:
            {
                printf("Print all info------------------\n");
                output_classroom(class, num_class);
                break;
            }
            case 5: 
            {
                printf("Sort info-------------------------\n");
                output_classroom(class, num_class);
                break;
            }
            case 6: free(class); break;
            default: free(class); break;
            }
    printf("Do you wanna quit? (y/n)\n");
    } while (getchar() != 'n');
}


int main()
{
    int num_class, selection = 0;
    Class *HQYJ = NULL;
    HQYJ = (Class *)malloc(sizeof(Class)*num_class);

    printf("Initializing database......\n");
    printf("How many class in HQYJ you wanna create: ");
    scanf("%d", &num_class);
    init_classroom(HQYJ, num_class);
    show_menu(HQYJ, num_class);

    return 0;
}