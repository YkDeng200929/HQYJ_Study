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
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("224.168.11.1"); // 组播地址
    saddr.sin_port = htons(atoi(argv[1]));
    socklen_t clen = sizeof(saddr);

	char buf[30] = {0};
	while (1)
	{
		bzero(buf, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&saddr, clen);
		printf("send: %s\n", buf);
	}
	close(sockfd);

    return 0;
}
