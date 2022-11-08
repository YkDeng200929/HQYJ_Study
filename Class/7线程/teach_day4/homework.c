#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void write_file(int fd)
{
	ssize_t write_bytes;
	char buf[32] = {0};

	while(1)
	{
		memset(buf, 0 ,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf) - 1] = '\0';
		write_bytes = write(fd, buf, strlen(buf));//父进程写入数据到文件
		if(write_bytes == -1)
		{
			perror("write");
			return ;
		}
		lseek(fd, -write_bytes, SEEK_CUR);//将文件指针移动到写入字符串之前
		if(strncmp(buf, "quit", 4) == 0)//如果前4个字符为quit则退出进程
		{
			break;
		}
	}

}

void read_file(int fd)
{
	ssize_t read_bytes;
	char buf[32] = {0};
	
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read_bytes = read(fd,buf,sizeof(buf));//子进程从文件中读数据
		if(read_bytes == -1)
		{
			perror("read");
			return ;
		}else if(read_bytes > 0)//读到数据则打印出来
		{
			if(strncmp(buf, "quit", 4) == 0)
			{
				break;
			}
			printf("buf: %s\n", buf);
		}else //读到文件末尾，跳出本次循环
		{
			continue;
		}
	}

}
int main(int argc, char **argv)
{
	int fd;
	pid_t pid;
	if(argc < 2)//如果只输入了少于2个字符串则报错
	{
		fprintf(stderr,"usage: %s [filename]\n",argv[0]);
		return -1;
	}
	fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);//打开test文件
	if(fd == -1)
	{
		perror("open test");
		return -1;
	}

	pid = fork();//创建子进程
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}else if(pid > 0)//父进程运行空间
	{
		write_file(fd);
	}else//子进程运行空间
	{
		read_file(fd);
	}

	close(fd);

	return 0;
}
