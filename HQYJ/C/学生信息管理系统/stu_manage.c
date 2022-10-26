#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2       // 每个班的最大人数

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
void init_classroom(Class *class, int num_class)
{
    memset(class, 0, sizeof(Class)*num_class);
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
        printf("===============================================CLASS: %d============================================\n", i+1);
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

// 修改学生信息 (无段错误, 但无法修改值)
void modify_info(Class *class, int class_num, int stu_id)
{
    printf("Modify name: ");
    scanf("%s", (class+class_num)->stu_info[stu_id-1].name);
    printf("Modify id: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id-1].id);
    printf("Modify score: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id-1].score);
    printf("Modify age: ");
    scanf("%d", &(class+class_num)->stu_info[stu_id-1].age);
}

// 学生分数由低到高排序 (无法排序)
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
    //char judge = 'y';
    
        // 插入学生到班级
        printf("Selections============================================================================\n");
        printf("<1>Insert student to class\n");
        // 删除班级中的某个学生
        printf("<2>Delete students info\n");
        // 修改学生信息
        printf("<3>Modify students info\n");
        // 输出所有班级内的学生信息
        printf("<4>Print all classroom students info\n");
        // 让学生信息按照成绩由低到高排序
        printf("<5>Sort info from low to greater one\n");
        // 关闭系统
        printf("<6>Close system\n");
        printf("Enter: ");
        scanf("%d", &selection);
        printf("=======================================================================================\n");
        switch (selection)
        {
            case 1: 
            {
                printf("Enter info:\n");
                //printf("Enter stu_id and class_num: ");
                //scanf("%d %d", &stu_id, &class_num);
                input_classroom(class, num_class);
                break;
            }
            case 2:
            {
                printf("Delete info:\n");
                printf("Enter stu_id and class_num: ");
                scanf("%d %d", &stu_id, &class_num);
                delete_info(class, class_num, stu_id);
                break;
            }
            case 3:
            {
                printf("Modify info:\n");
                printf("Enter stu_id and class_num: ");
                scanf("%d %d", &stu_id, &class_num);
                modify_info(class, class_num, stu_id);
                break;
            }
            case 4:
            {
                printf("Print all info\n");
                output_classroom(class, num_class);
                break;
            }
            case 5: 
            {
                printf("Sort info\n");
                sort_info(class, num_class);
                break;
            }
            case 6: free(class); break;
            default: free(class); break;
        }
}


int main()
{
    int num_class, selection = 0;
    int judge;
    Class *HQYJ = NULL;
    // 创建教室并初始化
    HQYJ = (Class *)malloc(sizeof(Class)*num_class);
    init_classroom(HQYJ, num_class);

    printf("Initializing database......\n");
    printf("How many class in HQYJ you wanna create: ");
    scanf("%d", &num_class);
    init_classroom(HQYJ, num_class);
    do
    {
        show_menu(HQYJ, num_class);
        printf("Do you want to quit?(y/n)\n");
        getchar();// getchar 接受换行
        scanf("%c", &judge);
    } while (judge != 'y');

    return 0;
}