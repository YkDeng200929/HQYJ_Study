#include <stdio.h>

int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int *p = a;
	int **q = &p;
	int i = 0;

	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//printf("%d ", p[i]);
		//*q = p
		//printf("%d ", (*q)[i]);
		//[] <==> *()
		printf("%d ", *(*q + i));
	}
	putchar('\n');

	return 0;
}

