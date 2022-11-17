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

struct client_info
{
	int connfd;
	struct sockaddr_in caddr;
};

void *cfd_do(void * arg)
{
	struct client_info cinfo = *(struct client_info *)arg;
	struct sockaddr_in caddr = cinfo.caddr;
	int connfd = cinfo.connfd;
	char buf[1024] = {0};
	while (1)
	{
		bzero(buf, sizeof(buf));
		int len = recv(connfd, buf, sizeof(buf), 0);
		printf("%s:%d  buf %s",inet_ntoa(caddr.sin_addr), ntohs(caddr.sin_port), buf);
		if (len == 0)
			break;
		send(connfd, buf, len, 0);
	}
	close(connfd);
}

int main(int argc, const char *argv[])
{
	int ret = 0;
	if (argc < 2)
	{
		printf("No port\n");
		exit(-1);
	}
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in saddr, caddr;
	bzero(&saddr, sizeof(saddr));
	bzero(&saddr, sizeof(caddr));
	socklen_t clen = sizeof(caddr);
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("192.168.9.56");
	saddr.sin_port = htons(atoi(argv[1]));

	ret = bind(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));
	if (ret < 0)
	{
		perror("bind");
		return -1;
	}

	ret = listen(sockfd, 10);
	if (ret < 0)
	{
		perror("listen");
		return -1;
	}
	
	char buf[1024] = {0};
	pthread_t tid;
	while(1)
	{
		int cfd = accept(sockfd, (struct sockaddr *)&caddr, &clen);
		if (cfd < 0)
		{
			perror("accept");
			return -1;
		}
		ret = pthread_create(&tid, NULL, cfd_do, (void *)&cfd);
		if (ret < 0)
		{
			perror("thread create");
			return -1;
		}

		pthread_detach(tid);
	}
	close(sockfd);

    return 0;
}
