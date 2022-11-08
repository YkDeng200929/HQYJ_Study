#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, pid2;
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        sleep(3);
        printf("child process exit\n");
        exit(0);
    }
    else
    {
        // wait 返回回收子进程的pid号
        pid2 = wait(NULL);
        printf("Child process pid = %d exit\n", pid2);
    }
    while(1);

    return 0;
}
