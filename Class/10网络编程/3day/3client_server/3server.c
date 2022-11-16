#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    //1. 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    //2. 准备自己的ip并将描述符与ip绑定
    struct sockaddr_in ip_info;
    bzero(&ip_info, sizeof(ip_info));
    ip_info.sin_family = AF_INET;
    ip_info.sin_port = htons(atoi(argv[1]));
    //3. ifconfig查自己的ip
    ip_info.sin_addr.s_addr = inet_addr("0.0.0.0");
    printf("client: %s\n", inet_ntoa(ip_info.sin_addr));
    socklen_t slen = sizeof(ip_info);

    if (bind(sockfd, (struct sockaddr *)&ip_info, slen) == -1)
    {
        perror("bind");
        return -1;
    }

    //4. 监听(阻塞状态等到有请求后再往下执行)
    listen(sockfd, 100);
    int conct_fd;

    // 准备接受客户端的 ip 信息
    struct sockaddr_in con_info;
    bzero(&con_info, sizeof(con_info));
    socklen_t clen = sizeof(con_info);

    //5. 接受请求
    conct_fd = accept(sockfd, (struct sockaddr *)&con_info, &clen);
    printf("I got a client request, ip: %s, port: %d\n", inet_ntoa(con_info.sin_addr), ntohs(con_info.sin_port));

    char buf[30] = {0};
    memset(buf, 0, sizeof(buf));

    /* TCP粘包问题: 
    引起原因之一发送方: 发送数据量比较小时会等待更多的数据然后一起发送
    引起原因之二接收方: 接收方从缓存区中读取数据, 读取速度较慢时, 缓存区的数据
                     会阻塞在一起(粘合在一起后一起发送)                  
            
    现象:  发送方       接收方
    第一次: hello ---->hellowo
    第二次发送: world---->rld
    解决方法: 
    1.应用层封装数据头  2.在数据中添加分隔符 */
    //sleep(8);

    while (1)
    {
        bzero(buf, sizeof(buf));
        if (recv(conct_fd, buf, sizeof(buf), 0) == -1)
        {
            perror("recv");
            return -1;
        }
        printf("buf: %s", buf);

        //6. 传消息
        if (send(conct_fd, buf, strlen(buf), 0) == -1)
        {
            perror("send");
            return -1;
        }

        if (strncmp(buf, "quit", 4) == 0)
        {
            printf("quit\n");
            close(sockfd);
            close(conct_fd);
            return 0;
        }
    }

    return 0;
}