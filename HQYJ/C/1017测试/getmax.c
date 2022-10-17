#include <stdio.h>

void get_max(int arr[3][4])
{
    int max_value = 0, max_row, max_col;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (arr[i][j] > max_value)
            {
                max_value = arr[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    printf("max_value: %d max_row: %d max_col: %d\n", max_value, max_row, max_col);
}

int main()
{
    int a[3][4] = {
        {123, 94, -10, 218},
        {3, 9, 10, -83},
        {45, 16, 44, -99}
    };
    get_max(a);
    
    return 0;
}