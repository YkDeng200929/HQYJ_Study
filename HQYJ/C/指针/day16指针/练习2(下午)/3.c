#include <stdio.h>

int main()
{
    char chart[26], alpha='A';
    int i;
    for (i = 0; i < 26; i++)
    {
        chart[i] = alpha;
        alpha++;
    }
    printf("%s\n", chart);

    return 0;
}