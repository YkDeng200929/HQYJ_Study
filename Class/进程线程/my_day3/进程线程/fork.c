#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    fork();
    printf("welcom to wuhan");
    putchar('\n');
    while(1);

    return 0;
}
