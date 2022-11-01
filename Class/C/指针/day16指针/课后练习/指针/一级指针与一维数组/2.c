#include <stdio.h>

int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    int *p = a;
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5 - i - 1; j++)
        {
            if (*(p+j) > *(p+j+1))
            {
                int temp;
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }
        }
    }
    int b = 0;
    /*
    while (*(a+b) != '\0')
    {
        printf("%d ", *(a+b));
        b++;
    }
    */
   for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}