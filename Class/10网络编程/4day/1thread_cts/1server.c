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

/*为了保证这两条语句视为一条语句, 所以使用do, while*/
#define ERR_LOG(VAL) do{perror(VAL);exit(-1);}while(0)
void * client_handler(void *arg)
{
	/*临时变量保存套接字(备份)*/
	int cfd_temp = *(int *)arg;
	int len = 0;
	char buf[1024] = {0};
	while (1)
	{
		memset(buf, 0, sizeof(buf));
		len = recv(cfd_temp, buf, sizeof(buf), 0);
		send(cfd_temp, buf, len, 0);
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
    ip_info.sin_family = AF_INET;
    ip_info.sin_addr.s_addr = inet_addr("127.0.0.1");/*INADDR_ANY <=> "0.0.0.0"绑定本机所有地址*/
    ip_info.sin_port = htons(atoi(argv[1]));
    printf("server ip: %s port: %d\n", inet_ntoa(ip_info.sin_addr), ntohs(ip_info.sin_port));
    socklen_t slen = sizeof(ip_info);
    struct sockaddr_in cnct_info;
    socklen_t clen = sizeof(cnct_info);
    bind(sockfd, (struct sockaddr *)&ip_info, slen);
    listen(sockfd, 100);

	pthread_t tid = -1;
	while (1)
	{
		int cfd = -1;
		if (cfd = accept(sockfd, NULL, NULL) == -1 )
			ERR_LOG("accept");
		
		pthread_create(&tid, NULL, client_handler, (void *)&cfd);

		pthread_detach(tid);
	}

    return 0;
}
