#include <stdio.h>
// 打开一个文件默认打开三个文件: 标准输入, 标准输出, 标准出错
int main(void)
{
    char *s = "jack";
    int age = 10;
    char sex = 'm';
    fprintf(stdout, "name %s age %d sex %c\n", s, age, sex);

    return 0;
}