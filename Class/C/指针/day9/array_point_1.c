#include <stdio.h>

int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int *p = NULL;
	int i = 0;

	p = a;//<=等价=>p = &a[0];

	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		//printf("%d ", a[i]);
		//printf("%d ", *(a + i));
		//printf("%d ", p[i]);
		//printf("%d ", *(p + i));
		//printf("%p ", (a + i));
		printf("%p ", (p + i));
	}
	putchar('\n');


	return 0;
}
