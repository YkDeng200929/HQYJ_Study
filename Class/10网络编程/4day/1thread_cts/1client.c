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

int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		printf("argv\n");
		exit(-1);
	}
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in ip_info;
    ip_info.sin_family = AF_INET;
    ip_info.sin_addr.s_addr = inet_addr("127.0.0.1");
    ip_info.sin_port = htons(atoi(argv[1]));
    socklen_t slen = sizeof(ip_info);
	// 不能将connect放入循环内
	if (connect(sockfd, (struct sockaddr *)&ip_info, sizeof(ip_info)) < 0)
	{
		perror("connect");
		return -1;
	}

	char buf[30] = {0};
	int fd = open("1.jpg", O_RDWR, 0666);
	if (fd < 0)
	{
		perror("open");
		return -1;
	}
	int ret;
    while (1)
    {
		bzero(&buf, sizeof(buf));
		ret = read(fd, buf, sizeof(buf));
		if (ret == 0)
			break;
		send(sockfd, buf, ret, 0);
    }
	printf("ok\n");
	close(sockfd);
	close(fd);
    

    return 0;
}
