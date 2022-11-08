#include <stdio.h>

int main()
{
    char a[100] = {0};
    char b[1024] = {0};
    scanf("%s", a);
    int count=0;
    int i=0;
    while(a[i] != '\0')
    {
        b[count++] = a[i++];
    }
    printf("%d\n", count);

    return 0;
}