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
#include <poll.h>
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
    struct pollfd rfds[100];
    for (int i = 0; i < 100; ++i)
    {
        rfds[i].fd = -1;
    }
    int lastPos = -1; // 实际表长度(表中元素个数)
    rfds[++lastPos].fd = sockfd;// 套接字放入表
    rfds[lastPos].events = POLLIN;// 事件类型
    
    printf("________rfds ok________\n");
	while(1)
	{
        ret = poll(rfds, lastPos + 1, -1);
    printf("________poll ok________\n");
        if (ret == -1)
        {
            perror("poll");
            return -1;
        }
        for (int i = 0; i < lastPos + 1; ++i)
        {
            if (rfds[i].revents & POLLIN) // 监听多个事件
            {
                if (rfds[i].fd == sockfd)
                {
                    int cfd = accept(sockfd, NULL, NULL);
                    printf("________accept ok________\n");
                    if (cfd < 0)
                    {
                        perror("accept");
                        continue;
                    }
                    rfds[++lastPos].fd = cfd;
                    rfds[lastPos].events = POLLIN;
                }
                else
                {
                    printf("______________in else____________\n");
                    memset(buf, 0, sizeof(buf));
                    ret = recv(rfds[i].fd, buf, sizeof(buf), 0); 
                    printf("______________Recv && Send ok____________\n");
                    if (ret <= 0)
                    {
                        rfds[i] = rfds[lastPos];
                        rfds[lastPos].fd = -1;
                        --lastPos;
                        close(rfds[i].fd);
                        //continue;
                        break;
                    }
                    send(rfds[i].fd, buf, strlen(buf), 0 ); 
                }
            }
        }
	}
	close(sockfd);

    return 0;
}
