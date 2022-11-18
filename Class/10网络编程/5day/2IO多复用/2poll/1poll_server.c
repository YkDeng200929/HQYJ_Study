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
    int lastPos = -1;
    rfds[++lastPos].fd = sockfd;// 套接字放入表
    rfds[lastPos].events = POLLIN;// 事件类型
    /*
    poll(rfds, lastPos + 1, -1);
    if (rfds[i].fd == fd)
    {}
    if (rfds[i].revents == POLLIN)// 事件触发时发送信号
    {}
    */
    
	while(1)
	{
        //printf("select ok\n");
        if (ret == -1)
        {
            perror("select");
            return -1;
        }
        for (int i = 0; i < 100; ++i)
        {
            if (rfds[i].revents == POLLIN)
            {
                if (i == sockfd)
                {
                    int cfd = accept(sockfd, NULL, NULL);
                    if (cfd < 0)
                    {
                        perror("accept");
                        continue;
                    }
                    rfds[++lastPos].fd = cfd;
                    rfds[++lastPos].events = POLLIN;
                }
                else if (i > 2)
                {
                        memset(buf, 0, sizeof(buf));
                        ret = recv(i, buf, sizeof(buf), 0); 
                        send(i, buf, strlen(buf), 0 ); 
                        if (ret <= 0)
                        {
                            rfds[i] = rfds[lastPos];
                            rfds[lastPos].fd = -1;
                            lastPos--;
                            continue;
                        }
                        else
                            break;
                }
            }
        }
	}
	close(sockfd);

    return 0;
}
