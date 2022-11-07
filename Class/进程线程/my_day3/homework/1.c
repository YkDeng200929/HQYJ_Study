#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    // 父进程写子进程读
    int fd;
    char buf[20];
    pid_t pid;

    fd = open("test.txt", O_RDWR, 0666);
    if (stat == -1)
    {
        perror("test.txt");
        return -1;
    }
    while (1)
    {
        pid = fork();
        if (pid > 0)
        {
            write(fd, buf, sizeof(buf));
        }
        if (pid == 0)
        {
            read(fd, buf, sizeof(buf));
            printf("%s", buf);
        }
    }
    
    return 0;
}
