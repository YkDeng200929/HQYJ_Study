#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	printf("input two num:");
	scanf("%d%d", &a, &b);
	if(a >= b)
	{
		printf("max:%d\n", a);
	}
	//if(a < b)
	else
	{
		printf("max:%d\n", b);
	}

	return 0;
}
