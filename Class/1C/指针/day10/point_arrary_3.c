#include <stdio.h>

int main()
{
	int a[3] = {5, 7, 2};
	int *buf[] = {&a[0], &a[1], &a[2], NULL};
	int i = 0;
	int **p = buf;

	for(i = 0; buf[i] != NULL; i++)
	{
		//printf("%d ", *buf[i]);
		//printf("%d ", *(*(p + i)));
		printf("%d ", *(p[i]));
	}
	putchar('\n');

	return 0;
}
