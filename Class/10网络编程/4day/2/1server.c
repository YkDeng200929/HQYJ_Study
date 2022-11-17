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

struct client_info
{
	int connfd;
	struct sockaddr_in caddr;
};

#define ERR_LOG(VAL) do{perror(VAL);exit(-1);}while(0)
void * client_handler(void *arg)
{
	struct client_info cinfo = *(struct client_info *)arg;
	int cfd_temp = cinfo.connfd;
	int len = 0;
	char buf[1024] = {0};
	while (1)
	{
		memset(buf, 0, sizeof(buf));
		len = recv(cfd_temp, buf, sizeof(buf), 0);
		printf("%s", buf);
		send(cfd_temp, buf, len, 0);
		printf("ip: %s, port: %d, cfd: %d\n", inet_ntoa(cinfo.caddr.sin_addr), ntohs(cinfo.caddr.sin_port) ,cinfo.connfd);
	}
	close(cfd_temp);
}

int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		printf("argv\n");
		exit(-1);
	}
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		ERR_LOG("socket");
    struct sockaddr_in ip_info;
	struct sockaddr_in cip_info;
    ip_info.sin_family = AF_INET;
    ip_info.sin_addr.s_addr = inet_addr("0.0.0.0");/*INADDR_ANY <=> "0.0.0.0"绑定本机所有地址*/
    ip_info.sin_port = htons(atoi(argv[1]));
    printf("server ip: %s port: %d\n", inet_ntoa(ip_info.sin_addr), ntohs(ip_info.sin_port));
    socklen_t slen = sizeof(ip_info);
    struct sockaddr_in cnct_info;
    socklen_t clen = sizeof(cnct_info);
    bind(sockfd, (struct sockaddr *)&ip_info, slen);
    listen(sockfd, 100);

	pthread_t tid = -1, tid2 = -1;
	struct client_info cifo;
	
	while (1)
	{
		socklen_t clen = sizeof(cip_info);
		int cfd = -1;
		if (cfd = accept(sockfd, (struct sockaddr *)&cip_info, &clen) == -1 )
			ERR_LOG("accept");
		cifo.connfd = cfd;
		cifo.caddr.sin_family = cip_info.sin_family;
		cifo.caddr.sin_port = cip_info.sin_port;
		cifo.caddr.sin_addr.s_addr = cip_info.sin_addr.s_addr;
		pthread_create(&tid, NULL, client_handler, (void *)&cfd);
		pthread_detach(tid);
	}

    return 0;
}
