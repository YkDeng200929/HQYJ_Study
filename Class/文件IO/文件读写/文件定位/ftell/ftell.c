#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    FILE *org;
    long int len;
    org = fopen("org.txt", "r+");
    if (org == NULL)
    {
        perror("org.txt");
        return -1;
    }
    //fseek(org, 0, SEEK_END);
    len = ftell(org);
    printf("%d\n", len);
    fclose(org);

    return 0;
}