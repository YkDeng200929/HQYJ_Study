#include <stdio.h>

int main(void)
{
    char buf[] ="helloqwdjw";

    sprintf(buf, "Good"); // ���ַ������ǵ� buf ��Ӧ��ַ���ַ���
    fprintf(stdout, "%s", buf);

    return  0;
}