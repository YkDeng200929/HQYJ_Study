#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


void *read_func(void *arg)
{
	static int re_number ;//用static修饰，线程结束后变量的值仍然存在
	re_number = *(int *)arg;
	re_number++;
	sleep(3);
	pthread_exit(&re_number);
}

int main()
{
	int ret;
	int a = 10;
	pthread_t tid1;
	int *p = NULL;
	ret = pthread_create(&tid1, NULL, read_func, &a);//创建子线程读文件
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}

	pthread_join(tid1,(void **)&p);//阻塞等待线程结束回收资源
	a = *p;
	printf("a = %d\n", a);
	return 0;
}
