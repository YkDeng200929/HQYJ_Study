#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct data
{
    int data_int;
    short data_short;
    char data_char;
} data;

int global = 0;

void *func(void *arg)
{
    data *data1 = (data *)arg;
    data1->data_int = 20;
    data1->data_short = 40;
    data1->data_char = 60;
    while (1)
    {
        sleep(1);
        printf("data1: %d, data2: %hd, data3: %c\n", data1->data_int, data1->data_short, data1->data_char);
        global++;
    }
}

void *func2(void *arg)
{
    int dat = *(int *)arg;
    while (1)
    {
        sleep(1);
        printf("global: %d data: %d\n", global, (*(int *)arg)++);
    }
}

int main(void)
{
    int dat = 10;
    // 1
    pthread_t tid;
    data data1;
    tid = pthread_create(&tid, NULL, func, &data1);
    if (tid != 0)
    {
        fprintf(stderr, "tid");
        return -1;
    }

    // 2
    pthread_t tid2;
    tid2 = pthread_create(&tid2, NULL, func2, &dat);


    while(1)
    {
        printf("main running: %d", dat);
        sleep(1);
    }
    exit(0);




    return 0;    
}