#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

void fun(int signum)
{
    // 非阻塞 WNOHANG
    // 阻塞 0
    pid_t pid;
    pid = waitpid(-1, NULL, WNOHANG);
    if (pid == -1)
    {
        perror("waitpid");
        return ;
    }
    printf("pid rec success pid = %d\n", pid);
}

int main(void)
{
    pid_t pid;
    if (signal(SIGCHLD, fun) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid > 0)
    {
        while (1)
        {
            printf("father do smething\n");
            sleep(1);
        }
    }
    else
    {
        sleep(10);
        exit(EXIT_SUCCESS);
    }


    return 0;
}