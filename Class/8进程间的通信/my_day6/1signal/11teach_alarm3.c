#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int count = 0;

void fun(int signum)
{
    alarm(3);
    count++;
    printf("Time out\n");
    if (count == 3)
    {
        printf("input timeout\n");
        exit(EXIT_SUCCESS);
    }
}
int main(void)
{
    char buf[32] = {0};
    int data;
    if (signal(SIGALRM, fun) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    alarm(3);
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        printf("Please enter an string\n");
        fgets(buf, sizeof(buf), stdin);
        printf("%s", buf);
        // 每次给你三次机会
        count = 0;
        // 覆盖上一个闹钟, 解决你输入了也会报 timeout 的错误
        alarm(3);
    }

    return 0;
}