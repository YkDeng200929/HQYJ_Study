#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void)
{
    int sock_fd;
    char buf[30] = {0};
    struct sockaddr_in ip_info;
    memset(&ip_info, '0', sizeof(ip_info));
    ip_info.sin_family = AF_INET;
    ip_info.sin_port = htons(2017);
    ip_info.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock_fd, (struct sockaddr *)&ip_info, sizeof(ip_info)) == -1)
    {
        printf("connect erro\n");
        return -1;
    }

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        read(sock_fd, buf, sizeof(buf));
        printf("%s\n", buf);
        sleep(1);
    }

    return 0;
}