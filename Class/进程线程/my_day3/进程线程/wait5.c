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
        sleep(300);
        printf("child process exit\n");
    }
    else
    {
        pid2 = wait(&stat);
        if (WIFEXITED(stat))
        {
            printf("WIFEXITED:%d\n", WIFEXITED(stat));
        }
        if (WIFSIGNALED(stat))
        {
            printf("WTERMSG : %d\n", WTERMSIG(stat));
        }

    }
    while(1);

    return 0;
}
