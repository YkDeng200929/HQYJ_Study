#include <stdio.h>
#include <pthread.h>

// 需要链接线程库
// gcc <文件> -lpthread && ./a.out

// 让线程执行的工作
void *func(void *arg)
{
	printf("hello world\n");
}

int main(void)
{

	int ret;
	// 创建线程号
	pthread_t tid;
	
	// 创建一个线程并创建线程函数
	ret = pthread_create(&tid, NULL, func, NULL);

	if (ret != 0)
	{
		fprintf(stderr, "thread creat fail");
		return -1;
	}

	while (1);

	return 0;
}
