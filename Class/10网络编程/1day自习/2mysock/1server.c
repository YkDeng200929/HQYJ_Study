#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void)
{
    int sock_fd = 0;
    int connected_fd;
    char buf[30] = {0};
    
    //1. socket
    if (sock_fd = socket(AF_INET, SOCK_STREAM, 0) == -1)
    {
        printf("sock error\n");
        return -1;
    }

    struct sockaddr_in ip_info;
    memset(&ip_info, '0', sizeof(ip_info));
    
    ip_info.sin_family = AF_INET;
    ip_info.sin_addr.s_addr = htonl(INADDR_ANY);
    ip_info.sin_port = htons(2017);

    //2.  绑定
    
    if (bind(sock_fd, (struct sockaddr *)&ip_info, sizeof(ip_info)) == -1)
    {
        printf("bind error\n");

        return -1;
    }
    

    //3. 监听
    listen(sock_fd, 5);

    //4. 接受请求
    while(1)
    {
        printf("server run\n");
        //if (connected_fd = accept(sock_fd, (struct sockaddr *)&ip_info, sizeof(ip_info)) == -1)
        //if (connected_fd = accept(sock_fd, NULL, NULL) == -1)
        if (connected_fd = accept(sock_fd, (struct sockaddr *)NULL, NULL) == -1)
        {
            printf("connected error\n");
            return -1;
        }
        
        //5. 若接受到请求, 就把消息写给连接套接字后发送出去
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);
        write(connected_fd, buf, sizeof(buf));

        close(connected_fd);
        sleep(1);
    }

    return 0;
}