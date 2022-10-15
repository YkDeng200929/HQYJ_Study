#include <stdio.h>

int main()
{
	int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int i = 0, j = 0;

	//输入
	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//控制列
		for(j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
		{
			//输入
			scanf("%d", &a[i][j]);
		}
	}

	//输出
	//控制行
	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//控制列
		for(j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
		{
			//输出
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
