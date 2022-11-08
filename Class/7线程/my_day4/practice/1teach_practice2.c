#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * func(void * arg)
{
    int val = *(int *)arg;
    while(1)
    {
        sleep(1);
        printf("thread %d\n", val);
    }
    pthread_exit(NULL);
}

int main(void)
{
    int i, ret;
    pthread_t tid[3];

    for (i = 0; i < 3; i++)
    {
        ret = pthread_create(&tid[0], NULL, func, &i);
        if (ret != 0)
        {
            fprintf(stderr, "create thread\n");
            return -1;
        }
        // 休眠一秒后子进程的结果会正常, why
        sleep(1);
    }

    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
    pthread_detach(tid[2]);

    /*
    sleep(10);
    pthread_cancel(tid[1]);
    */
    pthread_exit(NULL);

    return 0;
}