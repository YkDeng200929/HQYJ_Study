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
#include <sys/time.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <signal.h>

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
	saddr.sin_addr.s_addr = inet_addr("192.168.61.132");
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

    // 建表
    // 1. 创建根节点
    int pefd = epoll_create(1);
    if (pefd == -1)
    {
        perror("epoll_create");
        return -1;
    }
    struct epoll_event fd_contain[20];

    // 将监听套接字挂到树上
    struct epoll_event val1;
    val1.data.fd = sockfd;
    val1.events = EPOLLIN;
    epoll_ctl(pefd, EPOLL_CTL_ADD, sockfd, &val1);

    
    printf("________epoll_ctl ok________\n");
	while(1)
	{
        int len = epoll_wait(pefd, fd_contain, 20, -1);
        printf("________epoll_wait ok________\n");
        if (len == -1)
        {
            perror("epoll");
            return -1;
        }
        for (int i = 0; i < len; ++i)
        {
            if (fd_contain[i].events & EPOLLIN) // 监听多个事件
            {
                if (fd_contain[i].data.fd == sockfd)
                {
                    printf("______________in if____________\n");
                    int cfd = accept(sockfd, NULL, NULL);
                    printf("________accept ok________\n");
                    if (cfd < 0)
                    {
                        perror("accept");
                        continue;
                    }
                    struct epoll_event new_val;
                    fd_contain[++len].data.fd = cfd;
                    fd_contain[len].events = EPOLLIN;
                    epoll_ctl(pefd, EPOLL_CTL_ADD, cfd, &new_val);
                    printf("______________out if____________\n");
                }
                else
                {
                    printf("______________in else____________\n");
                    memset(buf, 0, sizeof(buf));
                    ret = recv(fd_contain[i].data.fd, buf, sizeof(buf), 0); 
                    printf("______________Recv ok____________\n");
                    if (ret < 0)
                    {
                        printf("______________out____________\n");
                        close(fd_contain[i].data.fd);
                        break;
                    }
                    send(fd_contain[i].data.fd, buf, strlen(buf), 0 ); 
                    printf("______________Send ok____________\n");
                    printf("______________out else____________\n");
                }
            }
        }
	}
	close(sockfd);

    return 0;
}
