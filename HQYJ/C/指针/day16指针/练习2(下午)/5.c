#include <stdio.h>

int main()
{
    int a[3][4] = {
        {1,2,3,10},
        {4,5,6,20},
        {7,8,9,30}
    };
    int row, col;
    scanf("%d %d", &row, &col);
    printf("%d\n", a[row-1][col-1]);

    return 0;
}