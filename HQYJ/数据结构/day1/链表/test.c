#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Book
{
    //char name[10];
    int price;
    struct Book * next;
};

bool creat_link(struct Book **lib, int size)
{
    lib = (struct Book *)malloc(sizeof(struct Book));
    if (lib == NULL)
        return false;
    return true;
}

bool insert_link(struct Book **lib, int price)
{
    struct Book *Book = NULL;
    Book = (struct Book *)malloc(sizeof(struct Book));
    if (Book == NULL)
}

int main()
{
    /*
    struct Book *library = NULL;
    // ด๓ะกฮช3
    library = (struct Book *)malloc(sizeof(struct Book)*3);
    for (int i = 0; i < 3; i++)
    {
        library[i].price = i;
        library[i].next = NULL;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("num: %d price: %d: Place: %p\n", i+1, library[i].price, library[i].next);
    }
    struct Book book1;
    .price = 999;
    library[0].next = &book1;
    book1.next = NULL;
    for (int i = 0; i < 3; i++)
    {
        printf("price: %d Place: %p\n", library[i].price, library[i].next);
    }
    */
    
    return 0;
}