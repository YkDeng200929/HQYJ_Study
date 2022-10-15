#include <stdio.h>

int main()
{
	int a[8];
	int n = 0;
	int sum = 0;
	int i = 0;
	int len = sizeof(a) / sizeof(a[0]);

	for(i = 0; i < len; i++)
	{
		scanf("%d", &a[i]);
		/*
		 * 第一种
		if(a[i] > 0)
		{
			n++;
			sum = sum +  a[i];
		}
		*/
	}
	// 第二种
	for(i = 0; i < len; i++)
	{
		if(a[i] > 0)
		{
			n++;
			sum += a[i];
		}
	}
	printf("sum:%d\nn:%d\n", sum, n);

	return 0;
}
