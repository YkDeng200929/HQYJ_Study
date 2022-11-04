#include <stdio.h>

void print(FILE *print)
{
    int val;
    while (1)
    {
        val = fgetc(print);
        // 位置放错
        //fputc(val, stdout);
        if (val == EOF)
            break;
        fputc(val, stdout);
    }
}

int main(void)
{
    FILE *org;
    org = fopen("org.txt", "r");
    if (org == NULL)
    {
        perror("org.txt");
        // 少了下面这句
        return -1;
    }
    print(org);
    fclose(org);

    return 0;
}