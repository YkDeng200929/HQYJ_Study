#include <stdio.h>
int min(int,int);
int main(void)
{
	int a,b;

	printf("Enter\n");
	while (scanf("%d %d", &a, &b) == 2)
	{
		printf("min is %d\n", min(a,b));
		printf("Enter next (q to quit)\n");
	}
	printf("Bye\n");

	return 0;
}

int min(int n, int m)
{
	return (n < m) ? n : m;
}
