#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int main(void)
{
    pid_t pid;
    
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    if (pid > 0);
    {
        while (1)
        {
            printf("father\n");
            sleep(1);
        }
    }
    if (pid == 0)
    {
        sleep(5);
        // 给自己发送信号
        raise(9);
        while(1);
    }


    return 0;
}