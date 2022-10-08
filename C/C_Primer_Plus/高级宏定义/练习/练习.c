#include <stdio.h>

int add(int num1, int num2)
{
    return num1 + num2;
}

int sub(int num1, int num2)
{
    return num1 - num2;
}

int calc(int  (*fp)(int, int), int num1, int num2)
{
    return (*fp)(num1, num2);
}

int (*select(char op))(int, int)
{
    switch(op)
    {
        case '+': return add;
        case '-': return sub;
    }
}

int main(void)
{
    int num1, num2;
    char op;
    int (*fp)(int, int);

    printf("请输入一个式子(eg:1+3)\n");
    scanf("%d%c%d", &num1, &op, &num2);

    

    return 0;
}