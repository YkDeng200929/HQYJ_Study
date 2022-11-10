#include <stdio.h>
#include <pthread.h>

int buf[10] = {1,2,3,4,5,6,7,8,9,10};
int len = sizeof(buf)/sizeof(buf[0]);//数组长度
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//定义并初始化互斥锁

void *func1(void *arg)
{
	int i;
	while(1)
	{
		pthread_mutex_lock(&mutex);//获得锁
		for(i = 0; i < len; i++)
		{
			printf("%d ", buf[i]);
		}
		putchar('\n');
		pthread_mutex_unlock(&mutex);//释放锁
	}
}
void *func2(void *arg)
{
	int i;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		for(i = 0; i < len/2; i++)//逆序
		{
			buf[i] ^= buf[len - i - 1];
			buf[len - i - 1] ^= buf[i];
			buf[i] ^= buf[len - i - 1];
		}
		pthread_mutex_unlock(&mutex);
		
	}
}
int main()
{
	int ret;
	pthread_t tid1, tid2;
	
	ret = pthread_create(&tid1, NULL, func1, NULL);
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}


	ret = pthread_create(&tid2, NULL, func2, NULL);
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread2\n");
		return -1;
	}

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}

