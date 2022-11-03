#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *log;
    log = fopen("log.txt", "w");
    fprintf(log, "welcom to wuhan\n");
    //fclose(log);// fclose 在关闭文件流时会刷新缓存

    while (1);

    return 0;
}