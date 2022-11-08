#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
void *func(void *arg)//线程执行函数
{
	int i = 0;
	static int value = 30;
	while(1)
	{
		sleep(1);
		if(i == 3)
		break;
		printf("thread 1 is running\n");
		i++;
	}
	printf("thread1 : = %p\n",&value);
	pthread_exit(&value);//子线程退出
}
int main()
{
	int ret;
	pthread_t tid;
	int *pval = NULL;
	ret = pthread_create(&tid, NULL, func, NULL);//创建线程函数
	if(ret != 0)
	{
		fprintf(stderr, "thread 1 create fail");
		return -1;
	}
	
	pthread_detach(tid);//将线程标记成分离式(非阻塞)，子线程结束后自动回收资源
	pthread_exit(NULL);//主线程退出

	return 0;
}
