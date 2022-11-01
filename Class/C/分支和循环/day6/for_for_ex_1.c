#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	int sum = 0, ret = 1;

	for(i = 1; i <= 7; i = i + 2)
	{
		for(j = 1, ret = 1; j <= i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("sum : %d\n", sum);

	return 0;
}
