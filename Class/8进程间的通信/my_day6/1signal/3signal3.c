#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signum)
{
    // 结合 switch 判断你发送的信号值
    switch (signum)
    {
        case SIGINT: printf("signum: %d\n", signum); break;
        case SIGTSTP: printf("signum: %d\n", signum); break;
    }
}

int main(void)
{
    if (signal(SIGINT, func) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }

    if (signal(SIGTSTP, func) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }

    while (1)
    {
        sleep(1);
        printf("welcom to wuhan\n");
    }

    return 0;
}