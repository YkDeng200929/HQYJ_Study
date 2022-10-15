#include <stdio.h>

int main()
{
	int a;
	int x = 0, y = 0, z = 0;

	printf("please input a num:");
	scanf("%d", &a);

	x = a / 100;
	y = a / 10 % 10;
	z = a % 10;

	printf("x:%d\ty:%d\tz:%d\n", x, y, z);

	return 0;
}
