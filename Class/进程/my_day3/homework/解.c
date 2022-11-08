#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void write_file(int fd)
{
	ssize_t write_bytes;
	char buf[32] = {0};

	while(1)
	{
		memset(buf,0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		write_bytes = write(fd, buf, strlen(buf));
		if (write_bytes == -1)
		{
			perror("write");
			return ;
		}
		lseek(fd, -write_bytes, SEEK_CUR);
	}
}

void read_file(int fd)
{
	ssize_t read_bytes;
	char buf[32] = {0};

	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read_bytes = read(fd, buf, sizeof(buf));
		if (read_bytes == -1)
		{
			perror("read");
			return ;
		}
		else if (read_bytes > 0)
		{
			printf("%s\n", buf);
		}
		else // 读到文件末尾
		{
			continue;
		}
	}

}

int main(int argc, char **argv)
{
	int fd;
	pid_t pid;

	fd = open("test", O_RDWR|O_CREAT|O_TRUNC, 0666);
	if (fd == -1)
	{
		perror("open test");
		return -1;
	}

	pid = fork();
	if (pid < 0) // 或者pid == -1
	{
		perror("fork");
		return -1;
	}
	else if (pid > 0)
	{
		write_file(fd);
	}
	else
	{
		read_file(fd);
	}


	return 0;
}
