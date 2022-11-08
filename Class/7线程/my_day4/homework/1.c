#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

void * fun(void *arg)
{
    char buf[20] = {0};
    int fd = *(int *)arg;
    ssize_t len;

    while (1)
    {
        len = read(fd, buf, strlen(buf));
        if (len == 0)
        {
            continue;
            sleep(1);
        }
    }
}

int main(void)
{
    // 打开
    int fd;
    pthread_t tid;
    fd = open("hello.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    // 创建子线程
    tid = pthread_create(&tid, NULL, fun, &fd);

    // 主线程
    char buf[20] = {0};
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        lseek(fd, -strlen(buf), SEEK_CUR);
        fgets()
        write(fd, buf, strlen(buf));
    }

    return 0;
}