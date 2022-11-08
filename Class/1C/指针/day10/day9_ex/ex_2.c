#include <stdio.h>

int main()
{
	int a[5] = {5, 4, 3, 2, 1};
	int *p = a;
	int i = 0, j = 0, temp = 0;
	int len = sizeof(a) / sizeof(a[0]);

	for(i = 0; i < len - 1; i++)
	{
		for(j = 0; j < len - 1 - i; j++)
		{
			//if(p[j] > p[j + 1])
			if(*(p + j) > *(p + j + 1))
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}

	for(i = 0; i < len; i++)
	{
		printf("%d ", *(p + i));
	}
	putchar('\n');

	return 0;
}
