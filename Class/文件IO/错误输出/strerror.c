#include <stdio.h>
#include <string.h> // �ṩ strerror() ԭ��
#include <errno.h>  // �ṩ errno
// errno -l     linux �鿴������˵��

int main(void)
{
    FILE *fp, *fp1;
    // r+ ��д������
    // w ������ɾ��ͬ���ļ�
    // w+ �������ļ�
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