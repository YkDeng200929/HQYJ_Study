#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void write_fd(int fd)
{
	char buf[32] = {0};
	ssize_t write_bytes;
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		write_bytes = write(fd, buf, strlen(buf));
		if(write_bytes == -1)
		{
			perror("write");
			return;
		}
	}

}

void read_fd(int fd)
{
	char buf[32] = {0};
	ssize_t read_bytes;
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read_bytes = read(fd, buf, sizeof(buf));
		if(read_bytes == -1)
		{
			perror("read");
			return;
		}else
		{
			printf("buf: %s\n", buf);
		}
	}

}
int main()
{
	int ret;
	pid_t pid;
	int fd[2];
	
	ret = pipe(fd);//创建无名管道
	if(ret == -1)
	{
		perror("pipe");
		return -1;
	}

	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("");
		return -1;
	}else if(pid > 0)//父进程运行空间
	{
		close(fd[0]);//关闭读
		write_fd(fd[1]);
	}else //子进程运行空间
	{
		close(fd[1]);//关闭写
		read_fd(fd[0]);
	}

	return 0;
}
