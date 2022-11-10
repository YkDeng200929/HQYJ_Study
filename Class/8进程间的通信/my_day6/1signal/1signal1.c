#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    //1. 以下是对信号的忽略操作, SIGINT(表示中断信号)
    // signal_interrupt
    // SIG_IGN (表示忽略信号)
    if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    {
    //2. if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    // signal_default 默认操作
        perror("signal");
        return -1;
    }

    if (signal(SIGTSTP, SIG_IGN) == SIG_ERR)
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