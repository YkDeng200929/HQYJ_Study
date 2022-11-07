#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int global = 10;
int main()
{
	int local = 20;
	int *val = (int *)malloc(sizeof(int));
	if(!val)
	return -1;
	*val = 30;
	pid_t pid;
	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}else if(pid == 0)//子进程执行的代码
	{
		local = 21;
		*val = 31;
		printf("pid = %d global = %d local = %d val = %d\n",pid,global,local,*val);
	}else//父进程执行的代码
	{
		global =11;
		printf("pid = %d global = %d local = %d val = %d\n",pid,global,local,*val);
	}

	//printf("pid = %d global = %d local = %d val = %d\n",pid,global,local,*val);
	return 0;
}
