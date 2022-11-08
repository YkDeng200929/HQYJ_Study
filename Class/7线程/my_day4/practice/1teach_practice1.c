#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * func1(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread1\n");
    }
    pthread_exit(NULL);
}

void * func2(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread2\n");
    }
    pthread_exit(NULL);
}

void * func3(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread3\n");
    }
    pthread_exit(NULL);
}

int main(void)
{
    int i, ret;
    pthread_t tid[3];

    ret = pthread_create(&tid[0], NULL, func1, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "create thread\n");
        return -1;
    }

    ret = pthread_create(&tid[1], NULL, func2, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "create thread\n");
        return -1;
    }

    tid[i] = pthread_create(&tid[3], NULL, func2, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "create thread\n");
        return -1;
    }

    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
    pthread_detach(tid[2]);

    sleep(10);
    pthread_cancel(tid[1]);

    pthread_exit(NULL);

    return 0;
}