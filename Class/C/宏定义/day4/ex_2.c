#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a = 'x';
	int b = 20;
	double c = 3.14159;

	printf("sizeof(a):%ld\n", sizeof(char));
	printf("sizeof(b):%ld\n", sizeof(int));
	printf("sizeof(c):%ld\n", sizeof(double));

	printf("a = %d\nb = %d\nc = %lf\n", a, b, c);
	
	return 0;
}
