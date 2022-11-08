#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	
	fd = open("file2",O_RDWR|O_CREAT|O_TRUNC,0777);//已读写方式打开一个文件，该文件不存在则创建，存在则清空文件内容，返回一个文件描述符
	if(fd == -1)
	{
		perror("file");
		return -1;
	}
	
	close(fd);//关闭文件描述符
	return -1;
}
