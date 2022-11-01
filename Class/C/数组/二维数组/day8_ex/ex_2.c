#include <stdio.h>

int main()
{
	int a[10][10] = {0};
	int i = 0, j = 0;

	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		for(j = 0; j <= i; j++)
		{
			if(0 == j)
			{
				a[i][0] = 1;
			}
			else
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
