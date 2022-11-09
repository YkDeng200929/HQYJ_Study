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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int pro = 0;

void * producer(void *arg)
{
    int data;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        data = rand() % 100;
        pro = data;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        sleep(1);
    }
    pthread_exit(NULL);
}

void * consumer(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        while (pro == 1)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("condum: %d\n", pro);
        // 少了下面这句
        pro = 0;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);

}

int main(void)
{
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    pthread_join(&tid1, NULL);
    pthread_join(&tid2, NULL);
    pthread_exit(NULL);

    return 0;
}