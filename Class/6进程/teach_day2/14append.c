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
	fd = open("file", O_RDWR|O_CREAT|O_APPEND,0666);//追加写
	if(fd == -1)
	{
		perror("file2");
		return -1;
	}

	write(fd, s, strlen(s));//把字符串写到文件末尾
	return 0;
}
