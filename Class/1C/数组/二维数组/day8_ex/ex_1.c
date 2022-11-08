#include <stdio.h>

int main()
{
	int a[3][4] = {0};
	int i = 0, j = 0;
	int row = 0, col = 0;

	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		for(j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("input row:");
	scanf("%d", &row);
	printf("input col:");
	scanf("%d", &col);

	if((row > 0 && row < 4) && (col > 0 && col < 5))
	{
		printf("%d\n", a[row - 1][col - 1]);
	}
	else
	{
		printf("input error\n");
	}

	return 0;
}
