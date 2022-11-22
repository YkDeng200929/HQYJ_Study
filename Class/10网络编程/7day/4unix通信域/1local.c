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
#include <sys/un.h>/*add*/

int main(int argc, const char **argv)
{
    int ret;
    int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == 0)
    {
        perror("socket");
        return 0;
    }    

    struct sockaddr_un saddr;//本地地址结构
    bzero(&saddr, sizeof(saddr));
    saddr.sun_family = AF_UNIX;

    /*判断s文件是否存在)*/
    if (access("/tmp/mysocket", F_OK) == 0)// 临时文件一般放在tmp下
    {
        printf("删除之前的套接字文件\n");
        unlink("/tmp/mysocket");// 删除s文件
    }
    strcpy(saddr.sun_path, "/tmp/mysocket");

    bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));

    ret = listen(sfd, 5);
    if (ret < 0)
    {
        perror("listen");
        return -1;
    }

    int cfd = accept(sfd, NULL, NULL);
    if (cfd < 0)
    {
        perror("accept");
        exit(-1);
    }

    char buf[1024] = {0};
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        int len = recv(cfd, buf, sizeof(buf), 0);
        if (len <= 0)
        {
            printf("client out\n");
            break;
        }

        printf("recv %s\n", buf);
    }
    close(cfd);
    close(sfd);

    return 0;
}