#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int buf[5] = {1,2,3,4,5};
pthread_t tid1, tid2;
pthread_mutex_t mutex =PTHREAD_MUTEX_INITIALIZER;

void * fun1(void *arg)
{
    int i;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        for (i = 0; i < 5; i++)
        {
            printf("%d", buf[i]);
        }
		putchar('\n');
        pthread_mutex_unlock(&mutex);
    }
}

void * fun2(void *arg)
{
    int i, j = 4;
	int temp;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        // 每次进入时初始化一遍, 就不会访问非法内存了
		j = 4;
        for (i = 0; i < 5 / 2; i++)
        {
			/*
			temp = buf[i];
			buf[i] = buf[5 - i - 1];
			buf[5 - i - 1] = temp;
			*/
			
			// 错误原因, j-- 后再次进入循环时没被初始化
			
            temp = buf[i];
            buf[i] = buf[j];
            buf[j] = temp;
			j--;
			
        }
        pthread_mutex_unlock(&mutex);
    }   
}

int main(void)
{
	int ret;
    ret = pthread_create(&tid1, NULL, fun1, NULL);
	if (ret != 0)
	{
		fprintf(stderr, "create thread\n");
		return -1;
	}
    ret = pthread_create(&tid2, NULL, fun2, NULL);
	if (ret != 0)
	{
		fprintf(stderr, "create thread\n");
		return -1;
	}
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
