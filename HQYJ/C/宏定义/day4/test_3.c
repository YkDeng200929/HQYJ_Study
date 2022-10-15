#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10;
	float b = 8.0;

	//a/b --> float
	//a --> int
	//a = a / b;

	//printf("%d\n", a);
	printf("%d\n", (int)(a / b));
	
	return 0;
}
