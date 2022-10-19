#include <stdio.h>

int main()
{
    int count = 0;
    int i, j, k;
    for (i  = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            for (k = 1; k <= 4; k++)
            {
                if (i != j && i != k && j != k)
                {
                    printf("%d%d%d ", i, j, k);
                    count++;
                }
            }
        }
    }
    printf("\ncount: %d\n", count);

    return 0;
}