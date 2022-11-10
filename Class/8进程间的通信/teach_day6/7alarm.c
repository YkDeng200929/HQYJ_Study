#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void alarm_handler(int signum)//信号处理函数
{
	alarm(3);
	printf("alarm %d \n",signum);
}

int main()
{
	pid_t pid;
	if(signal(SIGALRM, alarm_handler) == SIG_ERR)//SIGALRM(闹钟信号),对闹钟信号执行捕捉操作，中断信号产生时进入alarm信号处理函数
	{
		perror("signal");
		return -1;
	}
	alarm(3);//3s后产生一个alarm信号
	while(1)
	{
		printf("today is fine day\n");
		sleep(1);
	}
	return 0;
}
