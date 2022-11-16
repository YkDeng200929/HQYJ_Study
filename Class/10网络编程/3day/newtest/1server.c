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

int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		return 0;
	}
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in ip_info;
    ip_info.sin_family = AF_INET;
    ip_info.sin_addr.s_addr = inet_addr("127.0.0.1");
    ip_info.sin_port = htons(atoi(argv[1]));
    printf("server ip: %s port: %d\n", inet_ntoa(ip_info.sin_addr), ntohs(ip_info.sin_port));
    socklen_t slen = sizeof(ip_info);

    struct sockaddr_in cnct_info;
    socklen_t clen = sizeof(cnct_info);

    bind(sockfd, (struct sockaddr *)&ip_info, slen);

    listen(sockfd, 100);

	char buf[30] = {0};
    while (1)
    {
		int connect_fd = accept(sockfd, (struct sockaddr *)&cnct_info, &clen);
		// 短连接每次会话完毕后会关闭与客户端的连接
		// 此时客户端得重连
        while (1)
        {
			bzero(&buf, sizeof(buf));
            recv(connect_fd, buf, sizeof(buf), 0);
			printf("%s", buf);
			break;
        }
        close(connect_fd);
    }

    return 0;
}
