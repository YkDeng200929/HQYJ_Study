#include <stdio.h>
#include <pthread.h>

void *func(void *arg)//线程执行函数
{
	
	printf("thread 1\n");

}
int main()
{
	int ret;
	pthread_t tid;//线程id
	
	ret = pthread_create(&tid, NULL, func, NULL);//创建线程函数
	if(ret != 0)
	{
		fprintf(stderr, "thread 1 create fail");
		return -1;
	}
	while(1);
	return 0;
}
