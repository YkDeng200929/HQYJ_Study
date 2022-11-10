#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signum)
{
	switch(signum)//根据不同的信号做不同的事情
	{
		case SIGINT:
		printf("SIGINT: %d\n",signum);
		break;
		case SIGTSTP:
		printf("SIGTSTP: %d\n",signum);
		break;
	}

}

int main()
{
	if(signal(SIGINT, func) == SIG_ERR)//SIGINT(中断信号),对中断信号执行捕捉操作，中断信号产生时进入func信号处理函数
	{
		perror("signal");
		return -1;
	}
	
	if(signal(SIGTSTP, func) == SIG_ERR)//SIGTSTP(暂停信号),对中断信号执行捕捉操作，暂停信号产生时进入func信号处理函数
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
