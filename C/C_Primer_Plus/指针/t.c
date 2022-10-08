#include <stdio.h>

int main(void)
{
	while (1)
	{
		int a, b;
		printf("Enter\n");
		scanf("%d %d", &a, &b);
		printf("%d\n", a % b);
	}

	return 0;

}
