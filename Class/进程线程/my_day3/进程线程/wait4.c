#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, pid2;
    pid = fork();
    int stat;
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        sleep(3);
        printf("child process exit\n");
        //exit(99);
        //也可以用return, 则stat会变成 return 的返回值
        return 99;
    }
    else
    {
        // wait 返回回收子进程的pid号
        pid2 = wait(&stat);
        if (WIFEXITED(stat))
        {
            printf("WEXITSTATUS:%d\n", WEXITSTATUS(stat));
        }

    }
    while(1);

    return 0;
}
