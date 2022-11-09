#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

struct data_t
{
	char name[20];
	int id;
	int score;
};
pthread_t tid1,tid2;//线程号定义为全局变量，这里方便线程执行函数使用
sem_t sem_input,sem_output;//定义输入和输出信号量
struct data_t stu;

void *input_thread(void *arg)
{
	while(1)
	{
		sem_wait(&sem_input);//向输入信号量申请资源
		memset(&stu, 0, sizeof(stu));
		scanf("%s%d%d",stu.name,&stu.id,&stu.score);
		if(strncmp(stu.name, "quit", 4) == 0)
		exit(EXIT_SUCCESS);
		sem_post(&sem_output);//释放资源给输出信号量
	}
	pthread_exit(NULL);
}

void *output_thread(void *arg)
{
	
	while(1)
	{
		sem_wait(&sem_output);//向输出信号量申请资源
		printf("name :%s  id : %d score : %d\n",stu.name,stu.id,stu.score);
		sem_post(&sem_input);//释放资源给输入信号量
	}
	pthread_exit(NULL);
}

int main()
{
	int fd;
	int ret;
	sem_init(&sem_input, 0, 1);//2个信号量初始化，输入信号量给资源为1，输出信号量给资源为0
	sem_init(&sem_output, 0, 0);
	ret = pthread_create(&tid1, NULL, input_thread, &fd);//创建子线程读文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}
	ret = pthread_create(&tid2, NULL, output_thread, &fd);//创建子线程写文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread2\n");
		return -1;
	}

	pthread_join(tid1,NULL);//阻塞等待线程结束回收资源
	pthread_join(tid2,NULL);

	return 0;
}
