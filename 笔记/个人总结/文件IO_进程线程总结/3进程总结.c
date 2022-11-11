#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// 进程的标识符为 PID, 每个进程都有自己的 PID(process identifer)
// 因为会调用系统中的内容, 所以头文件含 sys

// 定义老头要干的事情
void father_do(void)
{
    printf("father doing\n");
}

// 定义儿子要干的事情
void child_do(void)
{
    printf("child doing\n");
}

int main(void)
{
    pid_t pid;
    //1. 创建一个子进程 (main 相当于父进程)
    pid = fork();
    
    //2. 让父进程干事情
    if (pid > 0)
    {
        while(1)
        {
            father_do();
            // 父亲用 wait 给孩子收尸
            wait(NULL);
            // waitpid
            sleep(1);
        }
    }

    //3. 让子进程干事情
    if (pid == 0)
    {
        while(1)
        {
            child_do();
            sleep(1);
            // 子进程死了没人收尸就会变成僵尸, 只有父亲能给他收尸
            exit(EXIT_SUCCESS);
        }
    }
    // 父子进程会拷贝一份全局资源共自己使用, 所以不会影响全局资源
    // 干活结束了可以关闭掉资源(下班了)
    // exit(EXIT_SUCCESS) 刷新缓存 库函数调用
    // _exit(EXIT_SUCCESS) 不刷新缓存 系统调用

    return 0;
}