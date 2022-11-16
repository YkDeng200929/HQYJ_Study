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
#include <signal.h>
#include <sys/wait.h>

void signalhandler(int signum)
{
	waitpid(-1,NULL,WNOHANG);
}

int main(int argc, const char *argv[])
{
	signal(SIGCHLD,signalhandler);

	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket");
		return -1;
	}
	
	//准备自己的ip,port
	struct sockaddr_in saddr;
	bzero(&saddr,sizeof(saddr));

	saddr.sin_family = AF_INET;
	//atoi:字符串-->整数
	saddr.sin_port = htons(atoi(argv[1]));
	saddr.sin_addr.s_addr = inet_addr("0.0.0.0");//"0.0.0.0"自动选用本机可用ip
	socklen_t slen = sizeof(saddr);

	int ret = bind(sockfd,(struct sockaddr *)&saddr,slen);
	if(-1 == ret)
	{
		perror("bind");
		return -1;
	}

	ret = listen(sockfd,100);
	if(-1 == ret)
	{
		perror("listen");
		return -1;
	}


	struct sockaddr_in caddr;
	bzero(&caddr,sizeof(caddr));
	socklen_t clen = sizeof(caddr);

	printf("wait...\n");
#if 0
	int cfd = accept(sockfd,(struct sockaddr *)&caddr,&clen);
	if(-1 == cfd)
	{
		perror("accept");
		return -1;
	}

	printf("port:%d,ip:%s\n",ntohs(caddr.sin_port),inet_ntoa(caddr.sin_addr));
#endif
	//TCP粘包问题：
	//发送方：发送数据量比较小时，会等待更多数据一起发送
	//接受方：接受方从缓存区中读取数据，读取速度较慢时，缓存区中的数据阻塞到一起
	//第一次发送：hello--->hellowo
	//第二次发送：world--->rld
	
	//解决办法：
	//应用层封装数据头
	//在数据中添加分隔符
	//sleep(8);
	char buf[64] = {0};


	while(1)
	{
		int cfd = accept(sockfd,(struct sockaddr *)&caddr,&clen);
		if(-1 == cfd)
		{
			perror("accept");
			return -1;
		}

		printf("port:%d,ip:%s\n",ntohs(caddr.sin_port),inet_ntoa(caddr.sin_addr));

		int fd = open("t1",O_RDWR|O_CREAT|O_TRUNC,0644);
		if(-1 == fd)
		{
			perror("open");
			return -1;
		}

		pid_t pid = fork();
		if(-1 == pid)
		{
			perror("fork");
			return -1;
		}
		else if(0 == pid)
		{
			close(sockfd);
			while(1)
			{
				bzero(buf,sizeof(buf));
				ret = recv(cfd,buf,sizeof(buf)-1,0);
				if(-1 == ret)
				{
					perror("recv");
					return -1;
				}
				else if(0 == ret)
				{
					break;
				}

				ret = write(fd,buf,ret);
				if(-1 == ret)
				{
					perror("write");
					return -1;
				}
			}
			close(cfd);
			close(fd);
			exit(0);
		}
		
		close(cfd);

	}

	close(sockfd);

	return 0;
}
