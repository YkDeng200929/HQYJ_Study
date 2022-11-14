#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

// 每执行一次服务端， 客户端就会收到一条消息

int main(void)
{
    time_t clock;
    char dataSending[1025];
    int clintListn = 0, clintConnt = 0;// 创建 socket

    // 该结构体用来表示地址信息 
    struct sockaddr_in ip0fServer;
    /*
    1、通常用 sockaddr_in 来保存某个网络地址, 在使用时强转成 sockaddr类型的指针
    struct sockaddr_in
    {
        short int sin_family; // 地址族
        unsigned short int sin_port; // 端口号
        struct in_addr sin_addr; // ip地址
        unsigned char sin_zero[8]; // 填充 0以保持与 struct sockaddr 同样大小
    }

    2、 sa_family 字段值:
        AF_INET: ipv4 协议
        AF+INET6: ipv6 协议
        AF_LOCAL: UNIX 域协议
        AF_LINK: 链路地址协议
        AF_KEY: 密钥套接字
    */

    // SOCK_STREAM 表示在通信的过程中使用 TCP 这种可靠的通信方式
    // AF_INET 表示使用 IPv4互联网协议
    clintListn = socket(AF_INET, SOCK_STREAM, 0);
    memset(&ip0fServer, '0', sizeof(ip0fServer));
    memset(dataSending, '0', sizeof(dataSending));

    // 打包, 将服务段的信息放入包中(包含端口, Ip地址)
    ip0fServer.sin_family = AF_INET;

    // h表示 host, n 表示network (host to network long) 端口号用 long 来处理: 返回转换字节序后的数值
    ip0fServer.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY 表示内核分配一个临时 IP地址

    // host to network short IP 地址用 short 来进行转换
    ip0fServer.sin_port = htons(2017);
    bind(clintListn, (struct sockaddr *)&ip0fServer, sizeof(ip0fServer));

    // 20表示最多只能有20个客户端能连接到服务器
    listen(clintListn, 20);
    while(1)
    {
        printf("\n\nHi, I am running server.Some Client hit me\n");

        // 运行无限循环保持服务器始终运行
        clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);

        clock = time(NULL);
        snprintf(dataSending, sizeof(dataSending), "%s\n", ctime(&clock)); // 打印成功给消息
        write(clintConnt, dataSending, strlen(dataSending));
        close(clintConnt);
        sleep(1);
    }

    return 0;
}