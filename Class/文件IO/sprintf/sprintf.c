#include <stdio.h>

int main(void)
{
    char buf[] ="helloqwdjw";

    sprintf(buf, "Good"); // 把字符串覆盖到 buf 对应地址的字符串
    fprintf(stdout, "%s", buf);

    return  0;
}