#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void child_handler(int signum)//信号处理函数
{
	pid_t pid;
	pid = waitpid(-1, NULL, WNOHANG);
	if(pid == -1)
	{
		perror("waitpid");
		return;
	}
	printf("child process is recycled successfully pid = %d\n", pid);
}

int main()
{
	pid_t pid;
	if(signal(SIGCHLD, child_handler) == SIG_ERR)//SIGINT(中断信号),对中断信号执行捕捉操作，中断信号产生时进入func信号处理函数
	{
		perror("signal");
		return -1;
	}
	
	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}else if(pid > 0)
	{
		while(1)
		{
			printf("father do something\n");
			sleep(1);
		}
	}else
	{
		sleep(5);
		exit(EXIT_SUCCESS);
	}

	return 0;
}
