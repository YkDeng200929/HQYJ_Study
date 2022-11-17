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
    
    struct sockaddr_in caddr;
    caddr.sin_family = AF_INET;
	// 指明的是主机的ip
    caddr.sin_addr.s_addr = inet_addr("192.168.61.132");
    caddr.sin_port = htons(atoi(argv[1]));
    socklen_t clen = sizeof(caddr);

	/*不需要绑定*/
	/*bind(sockfd, (struct sockaddr *)&caddr, clen);*/

	char buf[30] = {0};
	while (1)
	{
		bzero(buf, sizeof(buf));
		printf("Enter:");
		fgets(buf, sizeof(buf), stdin);
		sendto(sockfd, (char *)buf, strlen(buf), 0, (struct sockaddr *)&caddr, clen);
	}
	close(sockfd);

    return 0;
}
