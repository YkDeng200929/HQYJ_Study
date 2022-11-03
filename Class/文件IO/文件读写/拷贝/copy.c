#include <stdio.h>
#include <string.h>

void copy_file(FILE *fp1, FILE *fp2)
{
    int val;

    // 依次将目标文件中的每个字符输入到复制文件的文件流中, 直到读到 EOF 时退出
    while (1)
    {
        // fgetc 得到的是文件流中的每个字符
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