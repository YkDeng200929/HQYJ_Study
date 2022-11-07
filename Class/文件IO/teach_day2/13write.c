#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int fd;
	ssize_t ret;
	char buf[32] = {0};
	char *s = "EDG is champion"	;
	fd = open("file2", O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd == -1)
	{
		perror("file2");
		return -1;
	}

	write(fd, s, strlen(s));//把字符串写到文件中去,此时文件指针在文件末尾
	lseek(fd, 0, SEEK_SET);//把文件指针定位到开头
	read(fd,buf,sizeof(buf));
	printf("buf: %s\n",buf);
	return 0;
}
