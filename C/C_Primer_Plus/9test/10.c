#include <stdio.h>
void to_binary(unsigned long n, int m)
{
	int r;

	r = n % m;
	if (n >= m)
		to_binary(n / m,0);
	putchar(r == 0? '0':'1');

	return;
}

int main(void)
{
	unsigned long number;
	int m;
	printf("Enter an integer (q to quit):\n");
	while (scanf("%lu", &number) == 1)
	{
		printf("Enter the next arguement:\n");
		scanf("%d", &m);
		printf("Binary equivalent: ");
		to_binary(number, m);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");

	}
	printf("Done.\n");

	return 0;
}
