#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *log;
    log = fopen("log.txt", "w");
    fprintf(log, "welcom to wuhan\n");
    //fclose(log);// fclose �ڹر��ļ���ʱ��ˢ�»���

    while (1);

    return 0;
}