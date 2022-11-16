#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int signum)
{
    waitpid(-1, NULL, WNOHANG);
}

int main(int argc, const char *argv[])
{
    // 信号尽早注册
    signal(SIGCHLD, signal_handler);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }
    struct sockaddr_in ip_info;
    bzero(&ip_info, sizeof(ip_info));
    ip_info.sin_family = AF_INET;
    ip_info.sin_port = htons(atoi(argv[1]));
    ip_info.sin_addr.s_addr = inet_addr("0.0.0.0");
    printf("client: %s\n", inet_ntoa(ip_info.sin_addr));
    socklen_t slen = sizeof(ip_info);
    if (bind(sockfd, (struct sockaddr *)&ip_info, slen) == -1)
    {
        perror("bind");
        return -1;
    }
    listen(sockfd, 100);


    char buf[30] = {0};
    memset(buf, 0, sizeof(buf));
    int conct_fd;
    struct sockaddr_in con_info;
    bzero(&con_info, sizeof(con_info));
    socklen_t clen = sizeof(con_info);
    conct_fd = accept(sockfd, (struct sockaddr *)&con_info, &clen);
    printf("I got a client request, ip: %s, port: %d\n", inet_ntoa(con_info.sin_addr), ntohs(con_info.sin_port));
    int fd = open("copy.jpg", O_RDWR|O_CREAT|O_TRUNC, 0777);
    int ret = 0;
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    /*创建子进程*/
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if(pid == 0)
    {
        close(sockfd);
        while (1)
        {
            bzero(buf, sizeof(buf));
            // 接受客户端传送的内容
            if (recv(conct_fd, buf, sizeof(buf), 0) == -1)
            {
                perror("recv");
                return -1;
            }
            // 写入数据到待复制文档
            ret = write(fd, buf, strlen(buf));
            if (ret == 0)
            {
                printf("copy ok\n");
                break;
            }
        }
        close(fd);
        close(sockfd);
        // 退掉子进程
        exit(0);
    }
    close(conct_fd);

    return 0;
}