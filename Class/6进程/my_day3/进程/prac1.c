#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    printf("org: %d\n", pid);
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if(pid > 0)
    {
        printf("father pid: %d\n", getpid());
        while (1);
    }
    else if(pid == 0)
    {
        printf("child pid: %d\n", getpid());
        while (1);
    }
    
    return 0;
}
