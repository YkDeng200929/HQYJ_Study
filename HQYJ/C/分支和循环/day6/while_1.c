#include <stdio.h>

int main()
{
	//1+2+3+..+100
	int i = 0;
	int sum = 0;

	while(i++ < 100)
	{
		printf("%d\n", i);
		sum += i;
	}

	printf("sum:%d\n", sum);

	return 0;
}
