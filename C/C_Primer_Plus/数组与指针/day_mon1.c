#include <stdio.h>
#define MONTHS 12

int main(void)
{
    int i = 29;
    int day[MONTHS] = {31, i, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (index = 0; index < MONTHS; index++) 
        printf("Month %2d has %2d days.\n", index + 1, day[index]);

    return 0;
}