#include "head.h"

int main()
{
	int fd;
	char *s = "I love study";
	
	fd = open("test_string", O_RDWR|O_CREAT|O_TRUNC, 0777);
	if(fd == -1)
	{
		perror("");
		return -1;
	}

	deamon_func();
	
	while(1)
	{
		sleep(1);
		write(fd, s, strlen(s));
	}

	return 0;
}
