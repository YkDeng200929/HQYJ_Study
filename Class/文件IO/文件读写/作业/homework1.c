#include <stdio.h>

void print(FILE *print)
{
    int val;
    while (1)
    {
        val = fgetc(print);
        fputc(val, stdout);
        if (val == EOF)
            break;
    }
}

int main(void)
{
    FILE *org;
    org = fopen("org.txt", "r");
    if (org == NULL)
    {
        perror("org.txt");
    }
    print(org);
    fclose(org);

    return 0;
}