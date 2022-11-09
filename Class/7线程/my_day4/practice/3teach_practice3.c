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
	// 下面错
	// 因为初始话时 re_number 并不知道 arg 是什么东西
	// 所以不让初始化
	// bss 与 data 的区别?
    static int re_number = *(int *)arg;
	// 下面对
    //static int re_number;
	//re_number = *(int *)arg;
    re_number++;
    sleep(3);
    pthread_exit(&re_number);
}


int main(void)
{
    int a = 10;
	int ret;
    pthread_t tid;
	int *p = NULL;
    ret = pthread_create(&tid, NULL, func1, &a);
	if (ret != 0)
	{
		fprintf(stderr, "create thread\n");
	}
	pthread_join(tid, (void **)&p);
	a = *p;
    printf("a: %d\n", a);

    pthread_exit(NULL);

    return 0;
}
