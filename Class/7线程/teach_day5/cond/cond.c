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
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;//定义和初始化条件变量

int pro = 0;
void *producer(void *arg)//生产者
{
	int data;
	while(1)
	{
		pthread_mutex_lock(&mutex);//获得互斥锁
		data = rand() % 100;//产生一个随机数赋值给pro
		pro = data;
		printf("producer: pro = %d\n",pro);
		pthread_mutex_unlock(&mutex);//释放互斥锁
		pthread_cond_signal(&cond);//唤醒条件变量
		sleep(1);
	}
	pthread_exit(NULL);
}

void *consumer(void *arg)//消费者
{
	
	while(1)
	{
		pthread_mutex_lock(&mutex);//获得互斥锁
		while(pro == 0)
		{
			pthread_cond_wait(&cond,&mutex);//等待条件变量，条件不满足阻塞线程
		}
		printf("pro = %d\n", pro);//消费产品
		pro = 0;//重新置0
		pthread_mutex_unlock(&mutex);//释放互斥锁
	}
	pthread_exit(NULL);
}

int main()
{
	int ret;
	ret = pthread_create(&tid1, NULL, producer, NULL);//创建子线程读文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}
	ret = pthread_create(&tid2, NULL, consumer, NULL);//创建子线程写文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread2\n");
		return -1;
	}

	pthread_join(tid1,NULL);//阻塞等待线程结束回收资源
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&mutex);//销毁互斥锁
	pthread_cond_destroy(&cond);
	return 0;
}
