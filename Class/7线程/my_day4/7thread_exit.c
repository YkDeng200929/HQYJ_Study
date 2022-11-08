#include <stdio.h>
#include <pthread.h>

void *func(void *arg)
{
	int i = 0;
	while (i != 3)
	{
		printf("hello world\n");
		i++;
	}

	pthread_exit(NULL);
}

int main(void)
{

	int ret;
	pthread_t tid;
	ret = pthread_create(&tid, NULL, func, NULL);
	
	if (ret != 0)
	{
		fprintf(stderr, "thread creat fail");
		return -1;
	}
	printf("main\n");
	// 因为如果注释掉下面, 主进程还没结束, 所以无法刷新缓冲区
	// 不会打印子线程中的内容
	//pthread_exit(NULL);

	return 0;
}
