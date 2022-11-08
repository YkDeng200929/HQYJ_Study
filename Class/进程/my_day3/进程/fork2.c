#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// getpid 得到当前进程pid
// getppid 得到当前子进程父进程的进程号

int main(void)
{
    pid_t pid;
    // 给父进程返回子进程的pid号

    pid = fork();
    printf("org pid: %d\n", pid);
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        // 让子进程执行的工作
        printf("This is child process, now pid: %d\n", pid);
        printf("Get child process pid: %d\n", getpid());
        printf("Get father process pid by getppid: %d\n", getppid());
    }
    else
    {
        // 让父进程执行的操作
        printf("This is father process: child process if: %d\n", pid);
        printf("Get father process pid: %d\n", getpid());
    }
    //printf("welcom to wuhan");
    //putchar('\n');
    while(1);

    return 0;
}
