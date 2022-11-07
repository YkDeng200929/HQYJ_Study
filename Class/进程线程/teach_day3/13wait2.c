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
		sleep(3);
		printf("child exit\n");
		//exit(88);//子进程退出，产生僵尸子进程
		return 66;
	}else//父进程执行的代码
	{
		pid2 = wait(&status);//回收僵尸子进程资源
		if(pid2 == -1)
		{
			perror("wait");
			return -1;
		}
		if(WIFEXITED(status))//判断是否因exit()或者_exit()退出，得到exit里的值
		{
			printf("child exit() or _exit() , return value = %d\n",WEXITSTATUS(status));
		}
		printf("child exit pid = %d\n",pid2);
	}
	while(1);
	return 0;
}
