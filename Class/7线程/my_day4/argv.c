#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int write_file(int fd)
{
	ssize_t write_bytes;
	char buf[32] = {0};

	while(1)
	{
		memset(buf,0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf) - 1] = '\0';
		write_bytes = write(fd, buf, strlen(buf));
		if (write_bytes == -1)
		{
			perror("write");
			return -1;
		}
		lseek(fd, -write_bytes, SEEK_CUR);
		if (strncmp(buf, "quit", 4) == 0)
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
		read_bytes = read(fd, buf, sizeof(buf));
		if (read_bytes == -1)
		{
			perror("read");
			return ;
		}
		else if (read_bytes > 0)
		{
			if (strncmp(buf, "quit", 4) == 0)
			{
				break;
			}
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
	// argc 表示传进的参数个数, 不会报errno, 所以需要
	// stderr
	if (argc < 2) // 如果输入少于两个字符的字符串则报错
	{
		fprintf(stderr, "usage: %s [filename]\n", argv[0]);
		return -1;
	}

	// argv 表示外部传参, argv[0] 是a.out, argv[1] 是 a.out 后面
	// 跟着的参数名 (gcc argcv.c && ./a.out <文件名>) <-- 针对此
	// 文件的理解
	fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, 0666);
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
		int ret;
		ret = write_file(fd);
		if (ret)
		{
			exit(0);
			wait(0);
		}
	}
	else
	{
		read_file(fd);
	}

	close(fd);


	return 0;
}
