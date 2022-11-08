#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

void deamon_func()
{
	pid_t pid;

	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("");
		return ;
	}else if(pid > 0)//父进程退出
	{
		exit(EXIT_SUCCESS);
	}else
	{
		setsid();//子进程中创建新会话
		chdir("/");//改变进程的工作目录到“/”
		umask(0);//重设文件掩码
		close(0);//关掉不需要的文件描述符
		close(1);
		close(2);
	
	}
}
