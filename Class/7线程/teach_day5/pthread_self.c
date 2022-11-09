#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>


void *input_thread(void *arg)
{
	printf("my thread ID is %ld\n",pthread_self());//得到当前线程的ID值
	pthread_exit(NULL);
}


int main()
{
	int ret;
	pthread_t tid1;
	ret = pthread_create(&tid1, NULL, input_thread, NULL);
	if(ret != 0)
	{
		fprintf(stderr, "fail to create thread1\n");
		return -1;
	}
	printf("main tid = %ld\n",tid1);
	pthread_join(tid1,NULL);//阻塞等待线程结束回收资源

	return 0;
}
