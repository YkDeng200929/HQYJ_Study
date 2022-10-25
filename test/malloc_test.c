#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct
{
    char *name;
    int age;
    float salary;
} employee;

int main()
{
    employee *p1;

    if ((p1 = (employee *)malloc(sizeof(employee))) == NULL)
    {
        printf("malloc struct error\n");
        return 0;
    }
    memset(p1, 0, sizeof(employee));

    return 0;
}