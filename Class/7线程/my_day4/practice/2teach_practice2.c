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
    while(1)
    {
        char buf[20] = {0};
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        write(fd, buf, sizeof(buf));
        lseek(fd, -(strlen(buf)-1), SEEK_CUR);
    }
}

void * func2(void * arg)
{
    int fd = *(int *)arg;
    char buf[20] = {0};
    while(1)
    {
        memset(buf,0,sizeof(buf));
        read(fd, buf, strlen(buf));
        lseek(fd, -(strlen(buf)-1), SEEK_CUR);
        printf("%s", buf);
    }
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