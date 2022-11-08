#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void *func(void *arg)
{
	static int val = 20;
	int i = 0;
	while (i != 3)
	{
		sleep(1);
		printf("hello world\n");
		i++;
	}

	pthread_exit(&val);
}

int main(void)
{

	int ret, ret2;
	int *pval = NULL;
	pthread_t tid;
	ret = pthread_create(&tid, NULL, func, NULL);
	
	if (ret != 0)
	{
		fprintf(stderr, "thread creat fail");
		return -1;
	}
	// 将线程标记成分离式(非阻塞)，子进程结束后自动回收资源
	pthread_detach(tid);
	sleep(2);
	pthread_cancel(tid);
	pthread_exit(NULL);

	return 0;
}
