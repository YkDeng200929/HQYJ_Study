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

/* select
select()和pselect()允许程序监视多个文件描述符，
直到一个或多个文件描述符为某些类型的I/0操作(例如，可能的输入)“准备就绪”。
如果一个文件描述符能够执行相应的I/0操作(例如，读(2)而不阻塞，或者写(2)足够小)，
那么它就被认为是就绪的。
 */
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
    fd_set rfds, temp;
    // 清空表
    FD_ZERO(&rfds);
    FD_ZERO(&temp);

    // 把监听描述符放进表 FD_SET
    FD_SET(sockfd, &rfds);
    int maxlen = sockfd+1;  // 这个表的大小是随请求用户个数增大而增加的
    printf("set ok\n");
	while(1)
	{
        int ret, cfd;   // cfd 表示 client file description
        temp = rfds;
        ret = select(maxlen, &rfds, NULL, NULL, NULL);
        printf("select ok\n");
        if (ret == -1)
        {
            perror("select");
            return -1;
        }
        for (int i = 0; i < maxlen; ++i)
        {
            if (FD_ISSET(i, &temp))
            {
                printf("FD_ISSE ok sockfd: %d\n", sockfd);
                if (i == sockfd)
                {
                    cfd = accept(sockfd, NULL, NULL);
                    printf("accept ok cfd: %d\n", cfd);
                    if (cfd < 0)
                    {
                        perror("accept");
                        return -1;
                    }
                    FD_SET(cfd, &temp);
                    printf("set cfd ok\n");
                    ++maxlen;
                }
                else if (i > 2)
                {
                    while (1)
                    {
                        memset(buf, 0, sizeof(buf));
                        char msg[] = "I got message";
                        recv(cfd, buf, sizeof(buf), 0);
                        send(cfd, buf, strlen(msg), 0 );
                        printf("recv && send ok\n");
                        if (strncmp(buf, "quit", 4) != 0)
                        {
                            continue;
                        }
                        else
                            break;
                    }
                    close(cfd);
                    FD_CLR(cfd, &temp);
                    --maxlen;
                    break;
                }
            }
        }
	}
	close(sockfd);

    return 0;
}
