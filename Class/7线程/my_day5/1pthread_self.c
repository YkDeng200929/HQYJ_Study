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
// pthread_self 获得当前线程的 tid

void * fun(void * arg)
{
    printf("Thread tid: %ld\n", pthread_self());
}

int main(void)
{
    int ret;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, fun, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "create thread\n");
        return -1;
    }
    printf("Main tid: %ld\n", tid);
    exit(EXIT_SUCCESS);

    pthread_exit(NULL);

    return 0;
}