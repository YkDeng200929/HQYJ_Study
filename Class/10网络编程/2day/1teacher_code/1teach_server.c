#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h> // 提供 sockaddr_in 结构体原型
#include <arpa/inet.h>
#include <string.h>

int main(void)
{
    // 1、申请socket file descripter
    //                   通信域     通信方式
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //  数据流(TCP):sock_stream    数据报(UDP): sock_dgram

    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    // 2、服务器绑定IP与端口号(方便客户端找到主机)

    struct sockaddr_in ip_info;
    socklen_t slen = sizeof(ip_info);
    bzero(&ip_info, sizeof(ip_info)); // 比memset好用
    ip_info.sin_family = AF_INET; // 在哪个范围进行通信?
    ip_info.sin_port = htons(8888);
    ip_info.sin_addr.s_addr = inet_addr("192.168.61.132"); // inet_addr 专门用于转换ip

    if (bind(sockfd, (struct sockaddr *)&ip_info, slen) == -1)
    {
        perror("bind");
        return -1;
    }

    // 3、监听
    if (listen(sockfd, 100) == -1)
    {
        perror("listen");
        return -1;
    }

    // 4、接受客户端的 ip及其长度
    struct sockaddr_in client_addr;
    socklen_t clen = sizeof(client_addr);
    bzero(&client_addr, sizeof(client_addr));
    
    // 5、返回链接文件描述符, 通过cfd来进行通信
    int connect_fd = 0;
    connect_fd = accept(sockfd, (struct sockaddr *)&client_addr, &clen);

    if (connect_fd == -1)
    {
        perror("accept");
        return -1;
    }

    printf("port: %d, ip: %s\n", ntohs(client_addr.sin_port), inet_ntoa(client_addr.sin_addr));

    return 0;
}