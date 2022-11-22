#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sqlite3.h>
#include <sys/epoll.h>
#include <sys/time.h>

int main(int argc, const char **argv)
{

    int ret = -1, count = 0, flag = -1;
    if (argc < 3)
    {
        printf("Please enter port and ip\n");
        exit(-1);
    }

    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == 0)
    {
        perror("socket");
        return 0;
    }
    
    int val = 1;// 填非0值
    socklen_t vlen = sizeof(val);
    ret = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));// 设置端口复用
    if (ret == -1)
    {
        perror("setsockopt");
        exit(-1);
    }

    struct sockaddr_in saddr, caddr;
    bzero(&saddr, sizeof(saddr));
    bzero(&caddr, sizeof(caddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = (htons(atoi(argv[2])));
    saddr.sin_addr.s_addr = inet_addr(argv[1]);
    socklen_t slen = sizeof(saddr);
    socklen_t clen = sizeof(caddr);

    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));

    ret = listen(sfd, 124);
    if (ret < 0)
    {
        perror("listen");
        return -1;
    }

    printf("log:[%d]:Listening\n", ++count);
    char buf[30] = {0};

    struct timeval tim = {5,0};
    socklen_t tlen = sizeof(tim);

    int cfd = -1;
    cfd = accept(sfd, (struct sockaddr *)&caddr, &clen);
    while (1)
    {
        memset(buf, 0, sizeof(buf));

        // 接受缓冲区大小
        getsockopt(cfd, SOL_SOCKET, SO_RCVBUF, &val, &vlen);
        // 设置超时
        ret = setsockopt(cfd, SOL_SOCKET, SO_RCVTIMEO, &tim, tlen);
        if (ret == -1)
        {
            perror("getsockopt");
            exit(-1);
        }

        while (1)
        {
            ret = recv(cfd, buf, sizeof(buf), 0);
            if (ret == -1)
            {
                printf("over time\n");
                continue;
            }
            send(cfd, buf, ret, 0);
            printf("buf: %d\n", val);
            close(cfd);
        }
    }

    return 0;
}