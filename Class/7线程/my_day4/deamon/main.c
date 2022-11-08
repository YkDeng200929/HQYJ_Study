#include "head.h"

int main(void)
{
	int fd;

	char *s = "welcom to wuhan";

	fd = open("hello.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

	if (fd == -1)
	{
		perror("");
		return -1;
	}

	deamon_fun();

	while (1)
	{
		sleep(1);
		write(fd, s, strlen(s));
	}


	return 0;
}
