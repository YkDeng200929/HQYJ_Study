#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[10];
    int price;
} Books;

// 初始化
void init_lib(Books *lib, int len)
{
    memset(lib, 0, sizeof(Books)*len);
}

// 录入数据
void input_lib(Books *lib, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Enter name: ");
        scanf("%s", lib[i].name);
        printf("Enter price: ");
        scanf("%d", &lib[i].price);
    }
}

// 输出信息
void output_info(Books *lib, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Bookname: %s, Bookprice: %d\n", lib[i].name, lib[i].price);
    }
}

int main(void)
{
    Books *library = NULL;
    int len;
    printf("Enter the size of library you want: ");
    scanf("%d", &len);
    library = (Books *)malloc(sizeof(Books)*len);
    init_lib(library, len);
    input_lib(library, len);
    output_info(library, len);
    free(library);

    return 0;
}