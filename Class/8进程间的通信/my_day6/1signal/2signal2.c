#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signum)
{
    // func会将外部的signumber(信号对应的值传进函数)
    printf("Interrupt signal: signum: %d\n", signum);
}

int main(void)
{
    // 当 SIGINT 信号产生时执行 func 函数
    if (signal(SIGINT, func) == SIG_ERR)
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