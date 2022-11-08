#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	printf("22091\n");//父子进程都会从fork之后的下一条语句开始执行
	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}else if(pid == 0)//子进程执行的代码
	{

	}else//父进程执行的代码
	{
	}
	while(1);
	return 0;
}
