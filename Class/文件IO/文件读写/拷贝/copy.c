#include <stdio.h>
#include <string.h>

void copy_file(FILE *fp1, FILE *fp2)
{
    int val;

    // ���ν�Ŀ���ļ��е�ÿ���ַ����뵽�����ļ����ļ�����, ֱ������ EOF ʱ�˳�
    while (1)
    {
        // fgetc �õ������ļ����е�ÿ���ַ�
        val = fgetc(fp1);
        if (val == EOF)
        {
            break;
        }
        fputc(val, fp2);
    }
}

int main(void)
{
    FILE *org, *dest;
    org = fopen("org.txt", "r");
    if (org == NULL)
    {
        perror("org.txt");
        return -1;
    }
    dest = fopen("copy.txt", "w+");
    if (dest == NULL)
    {
        perror("copy.txt");
        return -1;
    }
    copy_file(org, dest);
    fclose(org);
    fclose(dest);
    

    return 0;
}