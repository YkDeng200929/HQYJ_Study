#include <stdio.h>

int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int *p = a;
	int i = 0;
	int len = sizeof(a) / sizeof(a[0]);

	for(i = 0; i < len; i++)
	{
		printf("%d ", *(a + i));
		printf("%d ", a[i]);
		printf("%d ", *(p + i));
		printf("%d ", p[i]);
	}
	putchar('\n');


	return 0;
}
