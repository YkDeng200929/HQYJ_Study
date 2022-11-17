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
	if (argc < 3)
	{
		printf("argv\n");
		exit(-1);
	}
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in ip_info;
    ip_info.sin_family = AF_INET;
    ip_info.sin_addr.s_addr = inet_addr(argv[2]);
    ip_info.sin_port = htons(atoi(argv[1]));
    socklen_t slen = sizeof(ip_info);
	// 不能将connect放入循环内
	if (connect(sockfd, (struct sockaddr *)&ip_info, sizeof(ip_info)) < 0)
	{
		perror("connect");
		return -1;
	}

	char buf[30] = "hello";
	send(sockfd, buf, sizeof(buf), 0);
	close(sockfd);
    

    return 0;
}
