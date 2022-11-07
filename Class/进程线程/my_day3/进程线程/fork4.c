#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    // 只打印一次, 因为是在创建子进程之前打印
    printf("hello\n");
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
    }
    else
    {
    }
    while(1);

    return 0;
}
