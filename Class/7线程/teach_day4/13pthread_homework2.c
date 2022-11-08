#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

void *func(void *arg)
{
	int val = *(int *)arg;
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
			ret = pthread_create(&tid[i], NULL, func,&i);
			if(ret != 0)
			{
				fprintf(stderr,"create thread%d fail\n",i);
				return -1;
			}
		sleep(1);
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
