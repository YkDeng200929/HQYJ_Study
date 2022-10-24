#include <stdio.h>

void find_max_min(int *max_num, int *min_num)
{
    int arr[7] = {10,23,45,78,90,4,6};
    int max, min;
    max = arr[0], min = arr[0];
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    *max_num = max;
    *min_num = min
}

int main()
{
    return 0;
}