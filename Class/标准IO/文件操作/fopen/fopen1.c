#include <stdio.h>
#include <string.h> // �ṩ strerror() ԭ��
#include <errno.h>  // �ṩ errno
// errno -l     linux �鿴������˵��

int main(void)
{
    FILE *fp;
    fp = fopen("log.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        // ������ļ���������, ����ͨ���ú����Ѵ����ӡ����
        return -1;
    }

    return 0;
}