#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in ip_info;
    bzero(&ip_info, sizeof(ip_info));
    ip_info.sin_family = AF_INET;
    ip_info.sin_port = htons(53561);
    ip_info.sin_addr.s_addr = inet_addr("192.168.61.2");
    socklen_t clen = sizeof(ip_info);
    connect(sockfd, (struct sockaddr *)&ip_info, clen);

    return 0;
}