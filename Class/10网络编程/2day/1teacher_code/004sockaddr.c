
//通用地址结构体
//The sockaddr structure is defined  as  something like:
struct sockaddr 
{
    sa_family_t      sa_family;//typedef unsigned short int sa_family_t;
    char             sa_data[14];
};
/*
注：这里的基本套接字地址结构体，只是作为一个模板用来接收本地套接字结构体变量地址
	或网络套接字结构体变量地址，也就是说它本身并不能直接使用；
*/

//网络套接字地址结构体：
#include <netinet/in.h>
struct sockaddr_in
{
    sa_family_t           sin_family;
    in_port_t             sin_port;//typedef uint16_t in_port_t;
    struct in_addr        sin_addr;   
};
struct in_addr
{
    in_addr_t             s_addr;//typedef uint32_t in_port_t;
};

//本地套接字地址结构体：
#include <sys/un.h>
struct sockaddr_un
{
    sa_family_t           sun_family; // 地址族(AF_LOCAL/AF_UNIX)
    char                  sun_path[108]; // 套接字文件路径
};


