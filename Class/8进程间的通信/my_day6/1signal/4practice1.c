#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>


pid_t pid;

void fun(int signum)
{
    waitpid(-1, NULL, 0);
}

int main(void)
{
    if (signal(SIGINT, fun) == SIG_ERR)
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
    if (pid > 0)
    {
        while (1)
        {
            sleep(1);
            printf("father do smething\n");
        }
    }
    if (pid == 0)
    {
        sleep(10);
        exit(EXIT_SUCCESS);
    }


    return 0;
}