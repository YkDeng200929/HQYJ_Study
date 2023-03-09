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
    // 建表(只判断文件描述符读缓冲区是否有数据)
    fd_set rfds, temp; // rfds表示读文件描述符
    // 清空表
    FD_ZERO(&rfds);
    FD_ZERO(&temp);

    // 把监听描述符放进表 FD_SET
    FD_SET(sockfd, &rfds);
    int maxlen = sockfd+1;
    printf("set ok\n");
	while(1)
	{
        //1. int cfd;
        temp = rfds; // 创建临时表, 避免数据丢失(因为内核在判断
                     // 完哪些文件描述符准备好后会修改文件描述符
                     // 表然后将表写回源内存地址)
        //ret = select(maxlen, &rfds, NULL, NULL, NULL);
        // 判断哪些文件描述符读缓冲区有写入, 然后记录到temp里面后返回
        ret = select(maxlen, &temp, NULL, NULL, NULL);
        printf("select ok\n");
        if (ret == -1)
        {
            perror("select");
            return -1;
        }
        // 遍历表, 判断该请求(套接字)对应的读缓冲区是否有数据
        // 若有数据则建立连接
        for (int i = 0; i < maxlen; ++i)
        {
            // temp表中的数据表示这些文件描述符有写入数据, 你可以
            // 接收连接后读数据了
            if (FD_ISSET(i, &temp))
            {
                printf("FD_ISSET ok sockfd: %d\n", sockfd);
                if (i == sockfd)
                {
                    int cfd;/*1*/
                    cfd = accept(sockfd, NULL, NULL);
                    printf("accept ok cfd: %d\n", cfd);
                    if (cfd < 0)
                    {
                        perror("accept");
                        //2. return -1;
                        continue; /*2*/
                    }
                    //3. FD_SET(cfd, &temp);
                    FD_SET(cfd, &rfds);/*3 一旦有客户端连接, 就将连接套接字写入源表(rfds)中*/
                    printf("set cfd ok\n");
                if (cfd + 1 > maxlen)
                {
                    maxlen = cfd + 1;
                }
            }
            else if (i > 2)
            {
                //while (1)
                //{
                    memset(buf, 0, sizeof(buf));
                    //4. recv(cfd, buf, sizeof(buf), 0);
                    //5. send(cfd, buf, strlen(msg), 0 );
                    ret = recv(i, buf, sizeof(buf), 0); /*4*/
                    send(i, buf, strlen(buf), 0 ); /*5*/
                    printf("recv && send ok\n");
                    if (ret <= 0)/*6: 此时说明客户端已退出*/
                    {
                        printf("client quit\n");
                        FD_CLR(i, &rfds);
                        if (i + 1 == maxlen)
                        {
                            --maxlen;
                        }
                        close(i);
                        continue;
                    }
                    /*
                    if (strncmp(buf, "quit", 4) != 0)
                    {
                        continue;
                    }
                    else
                        break;
                    */
                //}
                //close(cfd);
                //FD_CLR(cfd, &temp);
                //--maxlen;
                //break;
                }
            }
        }
	}
	close(sockfd);

    return 0;
}
