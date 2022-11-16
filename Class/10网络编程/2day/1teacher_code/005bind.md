# ip信息结构体[查找方法](#ip信息结构体查找方法)

                struct sockaddr_in saddr;
                bzero(&saddr, sizeof(saddr));
                saddr.sin_family = AF_INET;
                //#include <stdlib.h> atoi函数将字符串转换为整数
                saddr.sin_port = htons(atoi("6666"));
                saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
                int ret = bind(sockfd, (struct sockaddr *)&saddr, sizeof(saddr));
                if(ret == -1)
                {
                    perror("bind");
                    return -1;
                }


# 补充端口相关函数：
## 字节序转换[(有关大端小端)](/笔记/1C语言.md)

                主机字节序 <=> 网络字节序
                #include <arpa/inet.h>
                uint32_t htonl(uint32_t hostlong);
                uint16_t htons(uint16_t hostshort);
                uint32_t ntohl(uint32_t netlong);
                uint16_t ntohs(uint16_t netshort);
                h    -    host，主机(字节序)
                to   -    到，把...转换到...
                n    -    network，网络(字节序)
                l    -    long版本，32位无符号整数
        s    -    short版本，16位无符号整数


# 补充ip地址相关函数：
## IP地址转换

                (网络字节序32位无符号)整数<=>(点分十进制)字符串
                #include <arpa/inet.h>
                //串->数
                in_addr_t inet_addr(const char *cp); 
                //串->数，转换成功返回0，失败返回-1。
                int inet_aton(const char *cp, struct in_addr *inp);
                //数->串，转换成功返回字符串指针，失败返回NULL。
                char *inet_ntoa(struct in_addr in); 


# 补充指定内存块清空函数：

                #include <strings.h>
                #include <string.h>
                void bzero(void *s, size_t n);
                void *memset(void *s, int c, size_t n);

# 快速查找结构体所在头文件方法
1. 切换到头文件所在目录
2. `grep "struct 结构体名 {" -nir`



