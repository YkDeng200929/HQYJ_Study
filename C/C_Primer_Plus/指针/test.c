#include <stdio.h>
int a;
int b = 0;

int main(void)
{
	
	
	printf("Before: a = %d, b = %d\n", a++,b++);

	++a;
	--b;
	printf("Now: a = %d, b = %d\n", a,b);

	return 0;
}
