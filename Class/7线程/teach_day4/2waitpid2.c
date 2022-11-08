#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t pid,pid2;
	int status;
	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}else if(pid == 0)//子进程执行的代码
	{
		sleep(100);
		printf("child exit\n");
	}else//父进程执行的代码
	{
		while(1)
		{
			pid2 = waitpid(-1,&status, WNOHANG);//回收僵尸子进程资源  此时等价与wait(&status)，使用的时阻塞方式调用
			if(pid2 == -1)
			{
				perror("waitpid");
				return -1;
			}else if(pid2 == 0)
			{
				printf("pid2 = %d\n", pid2);
				continue;
			}else
			{
				if(WIFEXITED(status))//判断是否因exit()或者_exit()退出，得到exit里的值
				{
					printf("child exit() or _exit() , return value = %d\n",WEXITSTATUS(status));
				}
				if(WIFSIGNALED(status))//判断是否因信号退出，得到信号的编号
				{
					printf("child terminates by signal ,signal number = %d\n", WTERMSIG(status));
				}
				printf("child exit pid = %d\n",pid2);
				break;
			}
		}
	}
	return 0;
}
