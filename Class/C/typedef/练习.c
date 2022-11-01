#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int id;
    int score;
}student;

void output(student *info, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("name: %s, id: %d, score: %d\n", info[i].name, info[i].id, info[i].score);
    }
}

void sort(student *info, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            int temp;
            if (info[j].score > info[j+1].score)
            {
                student temp;
                temp = info[j];
                info[j] = info[j+1];
                info[j+1] = temp;
            }
        }
    }
}

int main()
{
    student st[3] = {
        {"Jack", 1, 100},
        {"Rose", 2, 80},
        {"Hmm", 3, 70}
    };
    int len = sizeof(st)/sizeof(st[0]);
    output(st, len);
    sort(st, len);
    output(st, len);

    return 0;
}