#include <stdio.h>

int main()
{
	int i = 1, sum = 0;

LOOP:
	if(i < 101)
	{
		sum = sum + i++;
		goto LOOP;
	}
	printf("sum : %d\n", sum);

	return 0;
}
