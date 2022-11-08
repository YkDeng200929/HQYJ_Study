#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

void deamon_fun(void)
{
	pid_t pid;
	// 创建守护进程的步骤(也就是能后台独立运行的进程)
	// 1, 创建子进程
	pid = fork();
	if (pid == -1)
	{
		perror("fork");

		return ;
	}
	else if (pid > 0)
	{
		// 2, 父进程退出
		exit(0);
	}
	else
	{
		// 3, 在子进程中创建新的会话(脱离终端控制)
		setsid();
		// 4, 改变进程的工作目录到 "/"
		chdir("/");
		// 5, 重设文件掩码
		umask(0);
	}
	// 6, 关闭不需要的文件描述符
}
