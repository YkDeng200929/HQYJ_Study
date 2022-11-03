#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *fp, *log;
    fp = fopen("Hello.txt", "r");
    log = fopen("log.txt", "w");
    if (fp == NULL)
    {
        perror("Hello"); // 用户自定义出错标签 (会在出错字段前面添加用户自定义的标签)
        // void perror(const char *s)
        return -1;
    }

    return 0;
}