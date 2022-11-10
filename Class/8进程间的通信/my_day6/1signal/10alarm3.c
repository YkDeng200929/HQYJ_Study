#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void fun(int signum)
{
    printf("please input\n");
}

int count = 0;

int main(void)
{
    int data;
    pid_t pid;
    if (signal(SIGALRM, fun) == SIG_ERR)
    {
        perror("signal");
        return -1;
    } 
    if (count < 3)
    {
        alarm(3);   
        count++;
        if (count == 3)
        {
            return -1;
        }
    }
    while (1)
    {
        printf("please Enter a number\n");
        scanf("%d", &data);
        count++;
    }

    return 0;
}