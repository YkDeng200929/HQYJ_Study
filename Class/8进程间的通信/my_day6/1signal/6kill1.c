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
        int i = 0;
        while (1)
        {
            printf("father\n");
            sleep(1);
            i++;
            if (i == 5)
            // 给指定的 pid 发送信号
            kill(pid, 9);
        }
    }
    if (pid == 0)
    {
        sleep(100);
    }


    return 0;
}