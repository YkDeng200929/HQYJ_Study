#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    //1. 创建套接字(通过套接字通信)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    //2. 准备服务器的地址
    struct sockaddr_in ip_info;
    bzero(&ip_info, sizeof(ip_info));
    ip_info.sin_family = AF_INET;
    // 端口号可以随机
    ip_info.sin_port = htons(atoi(argv[1]));// 指明主机端口
    ip_info.sin_addr.s_addr = inet_addr("127.0.0.1");// 指明与服务器通信的地址 

    //3. 与服务器连接(连接后就可以用sockfd进行通信了)
    if (connect(sockfd, (struct sockaddr *)&ip_info, sizeof(ip_info)) == -1)
    {
        perror("connect");
        return -1;
    }

    char buf[30] = {0};
    int ret = 0;
    int fd = 0;
    fd = open(argv[2], O_RDONLY);
    while(1)
    {
        
        memset(buf, 0, sizeof(buf));
        if (fd == -1)
        {
            perror("open");
            return -1;
        }
        ret = read(fd, buf, sizeof(buf));
        if (ret == 0)
        {
            break;
        }
        send(sockfd, buf, ret, 0);
    }
    close(fd);
    close(sockfd);

    return 0;
}
