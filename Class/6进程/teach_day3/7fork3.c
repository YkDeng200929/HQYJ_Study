#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}else if(pid == 0)//子进程执行的代码
	{
		printf("this is child process\n");
		printf("child getpid = %d\n",getpid());//得到当前进程的进程号
		printf("child getppid = %d\n",getppid());//得到父进程的进程号

	}else//父进程执行的代码
	{
		printf("I am your father process, get child process ID=%d\n",pid);
		printf("father getpid = %d\n",getpid());//得到当前进程的进程号
	}
	while(1);
	return 0;
}
