#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

pthread_t tid1,tid2;//线程号定义为全局变量，这里方便线程执行函数使用
sem_t sem_read,sem_write;//定义读和写信号量
void *write_func(void *arg)
{
	int fd = *(int *)arg;
	char buf[32] = {0};
	ssize_t write_bytes;
	while(1)
	{
		sem_wait(&sem_write);//向写信号量申请资源
		putchar('>');
		memset(buf,0,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf) - 1] = '\0';//'\n'替换'\0'
		write_bytes = write(fd, buf, strlen(buf));
		if(write_bytes == -1)
		{
			perror("write");
			break;
		}
		if(strncmp(buf,"quit",4) == 0)
		{
			pthread_cancel(tid1);//如果输入quit则取消读线程
			break;
		}
		lseek(fd, -write_bytes, SEEK_CUR);//将文件指针定位到写入的字符串之前
		sem_post(&sem_read);//释放资源给读信号量
	}
	close(fd);
	pthread_exit(NULL);
}

void *read_func(void *arg)
{
	int fd = *(int *)arg;
	char buf[32] = {0};
	ssize_t read_bytes;
	
	while(1)
	{
		sem_wait(&sem_read);//向读信号量申请资源
		memset(buf,0,sizeof(buf));
		read_bytes = read(fd, buf, sizeof(buf));
		if(read_bytes == -1)
		{
			perror("read");
			break;
		}else if(read_bytes == 0)
		{
			continue;
		}else
		{
			printf("buf:%s\n",buf);
		}
		sem_post(&sem_write);//释放资源给写信号量
	}
	pthread_exit(NULL);
}

int main()
{
	int fd;
	int ret;
	sem_init(&sem_read, 0, 0);//2个信号量初始化，写信号量给资源为1，读信号量给资源为0
	sem_init(&sem_write, 0, 1);
	fd = open("log", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	ret = pthread_create(&tid1, NULL, read_func, &fd);//创建子线程读文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}
	ret = pthread_create(&tid2, NULL, write_func, &fd);//创建子线程写文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread2\n");
		return -1;
	}

	pthread_join(tid1,NULL);//阻塞等待线程结束回收资源
	pthread_join(tid2,NULL);

	return 0;
}
