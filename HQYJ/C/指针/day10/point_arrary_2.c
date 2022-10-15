#include <stdio.h>

int main()
{
	int a = 5, b = 2, c = 9;
	int *p_array[] = {&a, &b, &c, NULL};
	int i = 0;

	for(i = 0; p_array[i] != NULL; i++)
	{
		printf("%p\t", p_array[i]);
		printf("%d\n", *p_array[i]);
	}

	return 0;
}
