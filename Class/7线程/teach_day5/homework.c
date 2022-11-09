#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

void *func(void *arg)
{
	int val = (int)arg;//强转回int型,4个字节，获得i传递过来的值
	while(1)
	{
		printf("thread val :%d is running\n",val);
		sleep(1);

	}

	
	pthread_exit(NULL);
}
int main()
{
	int i;
	int ret;
	pthread_t tid[3];
	for(i = 0; i < 3; i++)
	{
			ret = pthread_create(&tid[i], NULL, func,(void *)i);//对i进行强转，这里64位地址，因此变成8个字节
			if(ret != 0)
			{
				fprintf(stderr,"create thread%d fail\n",i);
				return -1;
			}
	//	sleep(1);
	}
	pthread_detach(tid[0]);
	pthread_detach(tid[1]);
	pthread_detach(tid[2]);
	
	/*sleep(10);
	pthread_cancel(tid[1]);
	*/
	pthread_exit(NULL);
	return 0;
}
