#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

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
int main(int argc, const char *argv[])
{
	int ret;
	int fd;
	if(argc < 2)
	{
		fprintf(stderr,"usage: %s [fifo_name]\n",argv[0]);
		return -1;
	}
	ret = mkfifo(argv[1], 0777);//创建有名管道文件，给与权限
	if(ret == -1 && errno != EEXIST)//排除掉文件存在的错误
	{
		perror("mkfifo");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);//以只读的方式打开文件，返回文件描述符
	if(fd == -1)
	{
		perror("open");
		return -1;
	}

	read_fd(fd);
	return 0;
}
