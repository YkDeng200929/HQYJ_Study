#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/un.h>/*add*/

int main(int argc, const char *argv[])
{
    int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    
    struct sockaddr_un saddr;
	bzero(&saddr, sizeof(saddr));
	saddr.sun_family = AF_LOCAL;
	if (access("/tmp/mysocket", F_OK | W_OK) == 0)
	{
		printf("File exist\n");
		strcpy(saddr.sun_path, "/tmp/mysocket");
	}
	else
	{
		exit(-1);
	}

	int ret = connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr));
	if (ret < 0)
	{
		perror("connect");
		exit(-1);
	}

	char buf[1024] = {0};
	while (1)
	{
		bzero(buf, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		write(sockfd, buf, strlen(buf));
	}
	close(sockfd);

    return 0;
}
