#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	
	fd = open("file",O_RDONLY);//以只读方式打开一个文件，该文件必须存在，返回一个文件描述符
	if(fd == -1)
	{
		perror("file");
		return -1;
	}
	
	close(fd);//关闭文件描述符
	return -1;
}
