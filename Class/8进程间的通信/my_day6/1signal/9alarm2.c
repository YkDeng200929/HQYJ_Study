#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void fun(int signum)
{
    alarm(3);
    printf("alarm\n");
}

int main(void)
{
    pid_t pid;
    if (signal(SIGALRM, fun) == SIG_ERR)
    {
        perror("signal");
        return -1;
    } 
    alarm(3);
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }

    return 0;
}