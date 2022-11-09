#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

pthread_t tid1, tid2;
char buf[128] = {0};
// 锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 条件变量
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int pro_id = 0;
void * producer(void *arg)
{
	int data;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		data = rand() % 100;
		pro_id = data;
		printf("Product out: %d\n", data);
		pthread_mutex_unlock(&mutex);
		// 唤醒消费者
		pthread_cond_signal(&cond);
		// 这样就不会两个都抢锁了
		sleep(1);
	}
	pthread_exit(NULL);
}

void * consumer(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		// 当消费者先抢到锁的时候, 先让他阻塞, 等生产者来唤醒消费者
		while (pro_id == 0)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		printf("Consumer consume: %d\n", pro_id);
		pro_id = 0;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}


int main(void)
{
	int ret;
	ret = pthread_create(&tid1, NULL, producer, NULL);
	ret = pthread_create(&tid1, NULL, consumer, NULL);

	pthread_join(tid1, NULL);	
	pthread_join(tid2, NULL);	
	pthread_mutex_destroy(&mutex);

    return 0;
}
