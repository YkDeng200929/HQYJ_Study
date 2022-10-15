#include <stdio.h>

int main()
{
	int a[6] = {4, 8, 3, 9, 7, 0};
	int i = 0, j = 0, k = 0;
	int len = sizeof(a) / sizeof(a[0]);
	int temp = 0;

	for(i = 0; i < len - 1; i ++)//轮数
	{
		printf("----------%d----------\n", i + 1);
		for(j = 0; j < len - 1 - i; j++)//每一轮循环次数
		{
			//小到大
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			for(k = 0; k < len; k++)
			{
				printf("%d ", a[k]);
			}
			putchar('\n');
		}
	}

	//输出
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	return 0;
}
