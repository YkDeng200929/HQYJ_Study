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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * fun1(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		memset(buf, 0, sizeof(buf));
		strcpy(buf, "hello");
		printf("%s", buf);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

void * fun2(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		memset(buf, 0, sizeof(buf));
		buf[0] = 'c';
		printf("%s", buf);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}


int main(void)
{
	int ret;
	ret = pthread_create(&tid1, NULL, fun1, NULL);
	ret = pthread_create(&tid1, NULL, fun2, NULL);

	pthread_join(tid1, NULL);	
	pthread_join(tid2, NULL);	
	pthread_mutex_destroy(&mutex);

    return 0;
}
