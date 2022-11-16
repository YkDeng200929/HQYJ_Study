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
    // 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    // 与ip绑定
    struct sockaddr_in ip_info;
    bzero(&ip_info, sizeof(ip_info));
    ip_info.sin_family = AF_INET;
    ip_info.sin_port = htons(2022);
    // ifconfig查自己的ip
    ip_info.sin_addr.s_addr = inet_addr("192.168.61.132");
    socklen_t slen = sizeof(ip_info);

    if (bind(sockfd, (struct sockaddr *)&ip_info, slen) == -1)
    {
        perror("bind");
        return -1;
    }

    // 监听(阻塞状态等到有请求后再往下执行)
    listen(sockfd, 100);

    // 接受请求
    while (1)
    {
        int conct_fd;
        struct sockaddr_in con_info;
        bzero(&con_info, sizeof(con_info));
        socklen_t clen = sizeof(con_info);
        conct_fd = accept(sockfd, (struct sockaddr *)&con_info, &clen);
        printf("I got a client request, ip: %s, port: %d\n", inet_ntoa(con_info.sin_addr), ntohs(con_info.sin_port));
        // 三次握手结束, 下面是四次挥手关闭
        close(conct_fd);
        sleep(1);
    }

    return 0;
}