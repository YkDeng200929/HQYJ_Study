#include <stdio.h>

int main()
{
	int a[] = {2, 4, 7, 1, 6, 9, 8, 3, 0, 5};
	int i = 0, j = 0, k = 0;
	//min存每次无序中最小的值
	//n存最小值的下标
	int min = 0, n = 0;
	int temp = 0;
	int len = sizeof(a) / sizeof(a[0]);

	for(i = 0; i < len - 1; i++)
	{
		min = a[i];
		n = i;
		for(j = i + 1; j < len; j++)
		{
			if(min > a[j])
			{
				min = a[j];
				n = j;
			}
		}
		if(n != i)
		{
			temp = a[n];
			a[n] = a[i];
			a[i] = temp;
		}
		printf("-------%d--------\n", i + 1);
		for(k = 0; k < len; k++)
		{
			printf("%d ", a[k]);
		}
		putchar('\n');
	}

	return 0;
}
