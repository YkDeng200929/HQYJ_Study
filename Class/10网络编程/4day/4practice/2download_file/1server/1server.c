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
#include <pthread.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	int ret = 0;
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in saddr;
	bzero(&saddr, sizeof(saddr));
	socklen_t slen = sizeof(saddr);
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("192.168.61.132");
	saddr.sin_port = htons(atoi(argv[1]));

	ret = bind(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));
	if (ret < 0)
	{
		perror("bind");
		return -1;
	}

	char buf[1024] = {0};
	ret = recvfrom(sockfd, (char *)buf, sizeof(buf), 0, (struct sockaddr *)&saddr, &slen);
	printf("%s\n", buf);
	int fd;
	// 优先级: 不要 if (fd = open() < 0)
	fd = open(buf, O_RDWR);
	if (fd < 0)
	{
		perror("open");
		char err[] = "error";
		sendto(sockfd, (char *)err, ret, 0, (struct sockaddr *)&saddr, slen); 
		return -1;
	}
	while (1)		
	{
		int ret;
		bzero(buf, sizeof(buf));
		ret = read(fd, buf,sizeof(buf));
		printf("read %s\n", buf);
		if (ret <= 0)
		{
			// !!! utp多此步
			sendto(sockfd, buf, 0, 0, (struct sockaddr *)&saddr, slen); 
			printf("copy ok\n");
			break;
		}
		sendto(sockfd, buf, ret, 0, (struct sockaddr *)&saddr, slen); 
	}
	close(fd);
	close(sockfd);

    return 0;
}
