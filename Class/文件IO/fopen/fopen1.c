#include <stdio.h>
#include <string.h> // 提供 strerror() 原型
#include <errno.h>  // 提供 errno
// errno -l     linux 查看错误码说明

int main(void)
{
    FILE *fp;
    fp = fopen("log.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        // 如果打开文件产生错误, 可以通过该函数把错误打印出来
        return -1;
    }

    return 0;
}