#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>

// 每执行一次服务端， 客户端就会收到一条消息
int main(void)
{
    int CreateSocket = 0, n = 0;
    // 用来装消息
    char dataReceived[1024];
    struct sockaddr_in ip0fServer;

    memset(dataReceived, '0',sizeof(dataReceived));

    if ((CreateSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket not created\n");
        return -1;
    }

    ip0fServer.sin_family =  AF_INET;
    ip0fServer.sin_port = htons(2017);
    ip0fServer.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(CreateSocket, (struct sockaddr *)&ip0fServer, sizeof(ip0fServer)) < 0)
    {
        printf("Connection failed due to port and ip problem\n");
        // 端口和ip有问题导致链接错误
        return -1;
    }

    while (n = read(CreateSocket, dataReceived, sizeof(dataReceived) - 1) > 0)
    {
        dataReceived[n] = 0;
        if (fputs(dataReceived, stdout) == EOF)
        {
            printf("\nStandard output error");
        }
        printf("\n");

    }

    if (n < 0)
    {
        printf("Standard input error\n");
    }

    return 0;
}