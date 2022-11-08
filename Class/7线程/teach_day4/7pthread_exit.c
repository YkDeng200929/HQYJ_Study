#include <stdio.h>
#include <pthread.h>

void *func(void *arg)//线程执行函数
{
	int i = 0;;
	while(1)
	{
		sleep(1);
		if(i == 3)
		break;
		printf("thread 1 is running\n");
		i++;
	}
	pthread_exit(NULL);//子线程退出
}
int main()
{
	int ret;
	pthread_t tid;
	ret = pthread_create(&tid, NULL, func, NULL);//创建线程函数
	if(ret != 0)
	{
		fprintf(stderr, "thread 1 create fail");
		return -1;
	}
	pthread_exit(NULL);//主线程退出
	return 0;
}
