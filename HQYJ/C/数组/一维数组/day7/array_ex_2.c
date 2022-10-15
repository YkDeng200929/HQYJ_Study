#include <stdio.h>

int main()
{
	int a[7] = {50, 20, 80, 9, 7, 8, 3};
	int max = 0;
	int n = 0;
	int len = sizeof(a) / sizeof(a[0]);
	int i = 0;

	for(i = 0; i < len; i++)
	{
		if(a[i] > a[n])
		{
			n = i;
		}
	}
	max = a[n];
	printf("max:%d\nn:%d\n", max, n);


	return 0;
}
