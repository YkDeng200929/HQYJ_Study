#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * func1(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread1\n");
        //pthread_exit(NULL);
    }
}

void * func2(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread2\n");
        //pthread_exit(NULL);
    }
}

void * func3(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread3\n");
        //pthread_exit(NULL);
    }
}

int main(void)
{
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, func1, NULL);
    pthread_create(&tid2, NULL, func2, NULL);
    pthread_create(&tid3, NULL, func3, NULL);

    pthread_detach(tid1);
    pthread_detach(tid2);
    pthread_detach(tid3);

    sleep(10);
    pthread_cancel(tid2);
    pthread_exit(NULL);

    return 0;
}