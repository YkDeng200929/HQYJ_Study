#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// getpid 得到当前进程pid
// getppid 得到当前子进程父进程的进程号
// 父子进程的调度取决于系统

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
    // 父子进程谁先执行取决于系统的调度算法
    else if (pid == 0)
    {
        // 让子进程执行的工作
        while (1)
        {
            sleep(1);
            printf("This is child\n");
        }
    }
    else
    {
        // 让父进程执行的操作
        while (1)
        {
            sleep(1);
            printf("This is father\n");
        }
    }
    //printf("welcom to wuhan");
    //putchar('\n');
    while(1);

    return 0;
}
