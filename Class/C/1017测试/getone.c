#include <stdio.h>

int get_one(int num)
{
    int count = 0;
    int temp = num;
    while (temp/2 != 0)
    {
        if (temp%2 == 1)
            count++;
        temp /= 2;
    }
    if (temp%2 == 1)
        count += 1;

    return count;
}


int main()
{
    printf("count_one: %d\n", get_one(34));

    return 0;
}