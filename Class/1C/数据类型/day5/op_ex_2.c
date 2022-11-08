#include <stdio.h>

int main()
{
	int x = 20, y = 30;
	int z = 0;

	z = ((++x) + (y++));

	printf("z:%d\n", z);

	return 0;
}
