#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int global = 10;

int main(void)
{
    int local = 20;
    int *val = (int *)malloc(sizeof(int));
    *val = 30;
    // 复制进程对变量的操作是相互独立的, 会拷贝一份源数据
    pid_t pid;
    printf("hello\n");
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        global = 11;
    }
    else
    {
        local = 21;
        *val = 31;
    }
    printf("pid: %d global: %d local: %d *val: %d\n", getpid(), global, local, *val);

    return 0;
}
