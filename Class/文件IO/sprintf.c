#include <stdio.h>

int main(void)
{
    char buf[] ="hello";

    sprintf(buf, "Good\n"); // ���ַ������ǵ� buf ��Ӧ��ַ���ַ���
    fprintf(stdout, "%s", buf);

    return  0;
}