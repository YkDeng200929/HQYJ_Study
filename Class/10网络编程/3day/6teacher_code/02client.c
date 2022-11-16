#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

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

	//sockfd
	char buf[64] = {0};

	while(1)
	{
		printf("input buf:\n");
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf)-1] = '\0';

		ret = send(sockfd,buf,strlen(buf),0);
		if(-1 == ret)
		{
			perror("send");
			return -1;
		}

		bzero(buf,sizeof(buf));
		ret = recv(sockfd,buf,ret,0);
		if(-1 == ret)
		{
			perror("recv");
			return -1;
		}

		if(strcmp(buf,"quit") == 0)
		{
			break;
		}

	}

	close(sockfd);

	return 0;
}
