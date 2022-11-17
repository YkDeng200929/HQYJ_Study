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
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in caddr;
    caddr.sin_family = AF_INET;
    caddr.sin_addr.s_addr = inet_addr("192.168.61.132");
    caddr.sin_port = htons(atoi(argv[1]));
    socklen_t clen = sizeof(caddr);

	// buf太小可能导致无法把大文件读完全
	char buf[1024] = {0};
	printf("Enter:");
	fgets(buf, sizeof(buf), stdin);
	buf[strlen(buf) - 1] = '\0';
	int fd = open(buf, O_RDWR|O_CREAT|O_TRUNC, 0666);
	sendto(sockfd, (char *)buf, strlen(buf), 0, (struct sockaddr *)&caddr, clen);
	while (1)
	{
		int  ret;
		memset(buf, 0, sizeof(buf));
		ret = recvfrom(sockfd, (char *)buf, sizeof(buf), 0, (struct sockaddr *)&caddr, &clen);
		//ret = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);都可以
		printf("read: %s", buf);
		if (strncmp(buf, "error", 4) == 0)
		{
			printf("No such file\n");
			return -1;
		}
		if (ret <= 0)
		{
			printf("copy ok");
			break;
		}
		else
		{
			write(fd, buf, ret);
		}
	}
	close(fd);
	close(sockfd);

    return 0;
}
