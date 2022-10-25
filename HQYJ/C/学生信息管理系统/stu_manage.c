#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3       // ÿ������������

typedef struct
{
    char name[16];
    int id;
    int score;
    int age;
} Stu;

typedef struct
{
    Stu stu_info[MAX];       // ѧ����Ϣ
    int n;                   // ��¼��ǰѧ������
} Class;


// init_classroom   ��ʼ���༶��Ϣ
void init_classroom(Class *class, int class_num)
{
    memset(class, 0, sizeof(Class)*class_num);
}

// input_student    ���뵥��ѧ����Ϣ
// ����: class_num ��ʾ �༶��, stu_id ��ʾѧ��ѧ��
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

// output_student   �������ѧ����Ϣ
// ����: class_num ��ʾ �༶��
void output_student(Class *class, int class_num, int stu_id)
{
    printf("Name: %s, Id: %d, Score: %d, Age: %d\n",
    (class+class_num)->stu_info[stu_id].name,
    (class+class_num)->stu_info[stu_id].id,
    (class+class_num)->stu_info[stu_id].score,
    (class+class_num)->stu_info[stu_id].age
    );
}

// input_classroom  ���༶ͳһ��ֵ
// ����: num_class ��ʾ �༶��
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

// output_classroom ����༶������ѧ����Ϣ
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

// ɾ��ѧ����Ϣ
void delete_info(Class *class, int class_num, int stu_id)
{
    memset(&((class+class_num)->stu_info[stu_id]), 0, sizeof(Stu));
}

// �޸�ѧ����Ϣ
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

// ѧ�������ɵ͵�������
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
        printf("<1>����ѧ�����༶\n");
        printf("<2>ɾ��ѧ�����༶\n");
        printf("<3>�޸�ѧ����Ϣ\n");
        printf("<4>������а༶�ڵ�ѧ����Ϣ\n");
        printf("<5>�ð༶�ڵ�ѧ�������ӵ͵�������\n");
        printf("<6>�ر�ѧ��ϵͳ\n");
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