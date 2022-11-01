#include <stdio.h>

void my_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int data1 = 10,  data2 = 20;

    return 0;
}