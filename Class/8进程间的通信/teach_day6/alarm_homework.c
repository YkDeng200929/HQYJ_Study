#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int count = 0;//设定一个全局变量，统计超时的次数
void alarm_handler(int signum)//信号处理函数
{
	alarm(3);
	count++;
	printf("timeout\n");
	if(count == 3)//超时3次退出进程
	{
		printf("iput timeout\n");
		exit(EXIT_SUCCESS);
	}
}

int main()
{
	char buf[32] = {0};
	if(signal(SIGALRM, alarm_handler) == SIG_ERR)//SIGALRM(闹钟信号),对闹钟信号执行捕捉操作，中断信号产生时进入alarm信号处理函数
	{
		perror("signal");
		return -1;
	}
	alarm(3);//3s后产生一个alarm信号
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		printf("buf : %s\n",buf);
		count = 0;
		alarm(3);//重置闹钟
	}
	return 0;
}
