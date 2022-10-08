#include <stdio.h>

struct library
{
    char bookname[10];
    int booknum;
};


int main(void)
{
    struct library lib[5] = 
    {
        {"C_prmier_plus", 888},
        {"ttes", 2},
        {},
        {},
        {},
    };

    for (int i = 0; i <= 5; i++)
    {
        printf("Book_Name:%s, Book_Number:%d\n", lib[i].bookname, lib[i].booknum);
    }
    

    return 0;
}