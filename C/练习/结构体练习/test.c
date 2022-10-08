#include <stdio.h>

int main()
{
    struct test{
        int a;
        int b;
    } hello;

    hello.a = 1;
    printf("%d\n", hello.a);

    return 0;
}