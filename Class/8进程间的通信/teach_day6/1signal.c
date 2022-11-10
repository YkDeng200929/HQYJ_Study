#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	/*if(signal(SIGINT, SIG_IGN) == SIG_ERR)//SIGINT(中断信号)，SIG_IGN(忽略信号)，对中断信号执行忽略操作
	{
		perror("signal");
		return -1;
	}*/
	if(signal(SIGINT, SIG_DFL) == SIG_ERR)//SIGINT(中断信号)，SIG_DFL(对信号默认处理，执行缺省操作)，对中断信号执行默认操作
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
