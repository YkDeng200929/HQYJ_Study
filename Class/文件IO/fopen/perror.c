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
        perror("Hello"); // �û��Զ�������ǩ (���ڳ����ֶ�ǰ������û��Զ���ı�ǩ)
        // void perror(const char *s)
        return -1;
    }

    return 0;
}