#include <stdio.h>
#include <string.h>

int main()
{
    char name[16] = {0};
    char id[16] = {0};
    char age[16] = {0};
    char info[48];

    strcpy(name, "ykdeng");
    strcpy(id, "531");
    strcpy(age, "18");
    strcat(info, name);
    strcat(info, id);
    strcat(info, age);

    
    printf("%s\n", name);
    printf("%s\n", id);
    printf("%s\n", age);
    printf("%s\n", info);

    return 0;
}