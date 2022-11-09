#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

pthread_t tid1,tid2;//线程号定义为全局变量，这里方便线程执行函数使用
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//定义和初始化互斥锁

char buf[128] = {0};
void *input_thread(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);//获得互斥锁
		memset(buf,0,sizeof(buf));
		strcpy(buf, "hello");
		printf("%s\n",buf);
		pthread_mutex_unlock(&mutex);//释放互斥锁
	}
	pthread_exit(NULL);
}

void *output_thread(void *arg)
{
	
	while(1)
	{
		pthread_mutex_lock(&mutex);//获得互斥锁
		memset(buf,0,sizeof(buf));
		buf[0] = 'c';
		printf("%s\n",buf);
		pthread_mutex_unlock(&mutex);//释放互斥锁
	}
	pthread_exit(NULL);
}

int main()
{
	int ret;
	ret = pthread_create(&tid1, NULL, input_thread, NULL);//创建子线程读文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}
	ret = pthread_create(&tid2, NULL, output_thread, NULL);//创建子线程写文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread2\n");
		return -1;
	}

	pthread_join(tid1,NULL);//阻塞等待线程结束回收资源
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&mutex);//销毁互斥锁
	return 0;
}
