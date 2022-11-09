#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
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

int main(int argc, const char *argv[])
{
	int ret;
	int fd;
	if(argc < 2)
	{
		fprintf(stderr,"usage: %s [fifo_name]\n",argv[0]);
		return -1;
	}
	ret = mkfifo(argv[1], 0777);//创建管道文件
	if(ret == -1 && errno != EEXIST )//排除文件存在的错误
	{
		perror("mkfifo");
		return -1;
	}
	
	fd = open(argv[1], O_WRONLY);//以只写的方式打开文件，返回文件描述符
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	
	write_fd(fd);
	

	return 0;
}
