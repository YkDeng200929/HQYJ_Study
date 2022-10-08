#include <stdio.h>
int main(void)
{
	int value = 1;

	while (value < 1024)
	{
		value <<= 1; // 向左移位相当于乘以２的２次幂
		printf("value = %d\n", value);
	}

	printf("\n---------------hello--------------\n");

	value = 1024;
	while (value > 0)
	{
		value >>= 2; // 向右移位相当于除以２的２次幂
		printf("value = %d\n", value);
	}

	return 0;
}
