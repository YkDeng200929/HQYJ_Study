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
#include <time.h>
#include <netinet/in.h> /*add*/
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[])
{
	int ret = 0;
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	// 加入组播组
	struct ip_mreq mreq;
	mreq.imr_multiaddr.s_addr = inet_addr("224.168.11.1");
	mreq.imr_interface.s_addr = inet_addr("0.0.0.0");

	ret = setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
	if (ret < 0)
	{
		perror("setsockopt");
		exit(-1);
	}

	struct sockaddr_in saddr;
	bzero(&saddr, sizeof(saddr));
	socklen_t slen = sizeof(saddr);
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	saddr.sin_port = htons(atoi(argv[1]));

	ret = bind(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));
	if (ret < 0)
	{
		perror("bind");
		return -1;
	}


	char buf[1024] = {0};
	while (1)		
	{
		memset(buf, 0, sizeof(buf));
		recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&saddr, &slen);
		printf("server recv %s\n", buf);
	}
	close(sockfd);

    return 0;
}
