#include <stdio.h>
#define MAX 5

typedef struct 
{
    char name[10];
    int price;
} lib;

void get_book(lib *books, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Enter the book name: ");
        scanf("%s", books[i].name);
        printf("Enter the book price: ");
        scanf("%d", &books[i].price);
    }
}

void get_info(lib *books, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Book name: %s\tBook price: %d\n", books[i].name, books[i].price);
    }
}

//void get_class_stu(lib *)

int main()
{
    lib books[5];
    get_book(books, 5);
    get_info(books, 5);

    return 0;
}