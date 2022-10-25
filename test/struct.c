#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[10];
    int price;
} books;

typedef struct
{
    books lib_info[4];
} lib;

int main()
{
    lib *library = NULL;
    library = (lib *)malloc(sizeof(lib)*5);
    strcpy((library+1)->lib_info[1].name, "hello");
    printf("%s\n", (library+1)->lib_info[1].name);

    return 0;
}