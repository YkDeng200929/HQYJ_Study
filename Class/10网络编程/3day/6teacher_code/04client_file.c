#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{	
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket");
		return -1;
	}
	
	//准备服务器的ip,port
	struct sockaddr_in saddr;
	bzero(&saddr,sizeof(saddr));

	saddr.sin_family = AF_INET;
	//atoi:字符串-->整数
	saddr.sin_port = htons(atoi(argv[1]));
	saddr.sin_addr.s_addr = inet_addr(argv[2]);// "127.0.0.1" 本地环回
	socklen_t slen = sizeof(saddr);
	
	int ret = connect(sockfd,(struct sockaddr *)&saddr,slen);
	if(-1 == ret)
	{
		perror("connect");
		return -1;
	}

	int fd = open(argv[3],O_RDWR);
	if(-1 == fd)
	{
		perror("open");
		return -1;
	}

	//sockfd
	char buf[64] = {0};

	while(1)
	{
		bzero(buf,sizeof(buf));
		ret = read(fd,buf,sizeof(buf));
		if(0 == ret)
		{
			printf("file end\n");
			break;
		}

		ret = send(sockfd,buf,ret,0);
		if(-1 == ret)
		{
			perror("send");
			return -1;
		}
	}

	close(fd);
	close(sockfd);

	return 0;
}
