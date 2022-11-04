#include <stdio.h>
#include <string.h> // 提供 strerror() 原型
#include <errno.h>  // 提供 errno
// errno -l     linux 查看错误码说明

int main(void)
{
    FILE *fp, *fp1;
    // r+ 读写并覆盖
    // w 创建并删除同名文件
    // w+ 创建空文件
    fp1 = fopen("log.txt", "w+");
    fp = fopen("log", "r");
    if (fp == NULL)
    {
        fprintf(fp1, "%s\n", strerror(errno));
        // char * strerror(int errno)
        return -1;
    }

    return 0;
}