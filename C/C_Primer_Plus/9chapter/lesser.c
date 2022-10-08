#include <stdio.h>
int imin(int, int);

int main(void)
{
	int evill, evill2;

	printf("Enter a pair of integer (q to quite)");
	while (scanf("%d %d", &evill, &evill2) == 2)
	{
		printf("The lesser of %d and %d is %d\n",
				evill, evill2, imin(evill, evill2));
	}
	printf("Bye\n");

	return 0;
}

int imin(int n,  int m)
{
	int min;
	
	if (n < m)
		min = n;
	else
		min = m;

	return min;
}
