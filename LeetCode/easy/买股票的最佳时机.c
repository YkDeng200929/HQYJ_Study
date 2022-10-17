#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    int good_day = 0;
    int max_get = 0;
    int now_max = 0;

    int i, j;
    for (i = 0; i < pricesSize; i++)
    {
        for (j = i + 1; j < pricesSize; j++)
        {
            now_max = prices[j] - prices[i];
            if ((now_max > max_get) && (prices[j] > prices[i]))
            {
                max_get = now_max;
                good_day = j;
            }
        }
    }
    return max_get;
}