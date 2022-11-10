#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signum)
{
	printf("INTERRUPT SIGNAL signum = %d\n",signum);

}

int main()
{
	if(signal(SIGINT, func) == SIG_ERR)//SIGINT(中断信号),对中断信号执行捕捉操作，中断信号产生时进入func信号处理函数
	{
		perror("signal");
		return -1;
	}
	
	while(1)
	{
		sleep(1);
		printf("today is fine day\n");
	}

	return 0;
}
