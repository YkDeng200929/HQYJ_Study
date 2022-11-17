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

	char buf[1024] = {0};
	int ret;
    while (1)
    {
		int connect_fd = accept(sockfd, (struct sockaddr *)&cnct_info, &clen);
		int fd = open("copy", O_RDWR|O_CREAT|O_TRUNC, 0666);
		if (fd < 0)
		{
			perror("open");
			return -1;
		}
		while (1)
		{
			bzero(&buf, sizeof(buf));
			ret = recv(connect_fd, buf, sizeof(buf), 0);
			if (ret == 0)
				break;
			write(fd, buf, ret);
			//write(fd, buf, strlen(buf));
			// 一定要注意write的第三个参数
			// 一定不要用strlen(buf)否则会导致有些内容没有完全读到
		}
		iprintf("copy ok\n");
		close(connect_fd);
		close(fd);
    }
	printf("ok");
	close(sockfd);

    return 0;
}
