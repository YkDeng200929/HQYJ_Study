#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

pthread_t tid1, tid2;

void * func1(void * arg)
{
    int fd = *(int *)arg;
    int len;
    // ssize_t 返回值缺少, 无法判断错误
    while(1)
    {
        char buf[20] = {0};
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        buf[strlen(buf) - 1] = '\0';
        len = write(fd, buf, strlen(buf));
        if (len == -1)
        {
            perror("write");
            return ;
        }
        // lseek 应放最尾部
        lseek(fd, -len, SEEK_CUR);
        if (strncmp(buf, "quit", 4) == 0)
        {
            pthread_cancel(tid1);
            // 少了上面这句
            break;
        }
    }
    pthread_exit(NULL);
}

void * func2(void * arg)
{
    int fd = *(int *)arg;
    char buf[20] = {0};
    while(1)
    {
        memset(buf,0,sizeof(buf));
        read(fd, buf, sizeof(buf));
        if (strncmp(buf, "quit", 4) == 0)
        {
            break;
        }
        // 如果读到文件结尾的条件缺少 read 的返回值为 0
        printf("%s", buf);
    }
    pthread_exit(NULL);
}

int main(void)
{
    int fd;
    fd = open("prac2.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    pthread_create(&tid1, NULL, func1, (void **)&fd);
    pthread_create(&tid2, NULL, func2, (void **)&fd);

    pthread_detach(tid1);
    pthread_detach(tid2);

    pthread_exit(NULL);

    return 0;
}