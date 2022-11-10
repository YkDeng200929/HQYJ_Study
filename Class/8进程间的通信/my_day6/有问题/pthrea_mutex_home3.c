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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem_fun1, sem_fun2;

void * fun1(void *arg)
{
    int i;
    while (1)
    {
		sem_wait(&sem_fun1);
        pthread_mutex_lock(&mutex);
        for (i = 0; i < 5; i++)
        {
            printf("%d", buf[i]);
        }
		putchar('\n');
        pthread_mutex_unlock(&mutex);
		sem_post(&sem_fun2);
    }
    pthread_exit(NULL);

}

void * fun2(void *arg)
{
    int i, j = 4;
    while (1)
    {
		sem_wait(&sem_fun2);
        pthread_mutex_lock(&mutex);
        for (i = 0; i < 5 / 2; i++)
        {
            int temp;
            temp = buf[i];
            buf[i] = buf[j];
            buf[j] = temp;
            j--;
        }
        pthread_mutex_unlock(&mutex);
		sem_post(&sem_fun1);
    }   
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tid1, tid2;
	int ret;
	sem_init(&sem_fun1, 0, 1);
	sem_init(&sem_fun2, 0, 0);
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
