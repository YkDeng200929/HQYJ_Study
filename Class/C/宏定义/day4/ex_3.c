#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 100;
	int b = 200;
	int temp = 0;

	printf("a = %d\tb = %d\n", a, b);

	temp = a;
	a = b;
	b = temp;

	printf("a = %d\tb = %d\n", a, b);
	
	return 0;
}
