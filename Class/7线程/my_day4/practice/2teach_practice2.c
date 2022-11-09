#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

pthread_t tid1, tid2;

void * write_fun2(void * arg)
{
	int fd = *(int *)arg;
    char buf[20] = {0};
	ssize_t write_bytes;
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        write_bytes = write(fd, buf, strlen(buf));
		if (write_bytes == -1)
		{
			perror("write:");
			break;
		}
		if (strncmp(buf, "quit", 4) == 0)
		{
			pthread_cancel(tid1);
			break;
		}
        lseek(fd, -write_bytes, SEEK_CUR);

    }
	pthread_exit(NULL);
}

void * read_fun1(void * arg)
{
    int fd = *(int *)arg;
    char buf[20] = {0};
	ssize_t read_bytes;
    while(1)
    {
        memset(buf,0,sizeof(buf));
        read_bytes = read(fd, buf, sizeof(buf));
		if (read_bytes == -1)
		{
			perror("write:");
			break;
		}
		else if (read_bytes == 0)
		{
			continue;
		}
		else
		{
			printf("%s", buf);
		}
    }
	pthread_exit(NULL);
}

int main(void)
{
    int fd, ret;
    fd = open("prac2.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    ret = pthread_create(&tid1, NULL, read_fun1, (void **)&fd);
	if (ret != 0)
	{
		fprintf(stderr, "create thread\n");
	}
    ret = pthread_create(&tid2, NULL, write_fun2, (void **)&fd);
	if (ret != 0)
	{
		fprintf(stderr, "create thread\n");
	}

    pthread_detach(tid1);
    pthread_detach(tid2);

    pthread_exit(NULL);

    return 0;
}
