#include <stdio.h>
// ��һ���ļ�Ĭ�ϴ������ļ�: ��׼����, ��׼���, ��׼����
int main(void)
{
    char *s = "jack";
    int age = 10;
    char sex = 'm';
    fprintf(stdout, "name %s age %d sex %c\n", s, age, sex);

    return 0;
}