#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

pthread_t tid1, tid2;

void * func1(void * arg)
{
    int re_number = *(int *)arg;
    re_number++;
    sleep(3);
    pthread_exit(NULL);
}


int main(void)
{
    int a = 10;
    pthread_t tid;
    pthread_create(&tid, NULL, func1, &a);
    printf("a: %d\n", a);

    pthread_exit(NULL);

    return 0;
}