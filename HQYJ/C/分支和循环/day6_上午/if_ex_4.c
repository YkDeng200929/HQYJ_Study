#include <stdio.h>

int main()
{
	int data = 0;
	int x = 0, y = 0, z = 0;
	int ret = 0;

	scanf("%d", &data);
	
	x = data / 100;
	y = data % 100 / 10;
	z = data % 10;

	if(0 != data % 2)//奇数
	{
		printf("%d %d %d \n", x, y, z);
	}
	else//偶数
	{
		ret = x * x * x + y * y * y + z * z * z;
		if(ret == data)
		{
			printf("%d is flower data\n", data);
		}
		else
		{
			printf("%d is not flower data\n", data);
		}
	}

	return 0;
}
