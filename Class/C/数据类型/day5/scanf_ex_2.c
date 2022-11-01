#include <stdio.h>

int main()
{
	char c, d;
	int a, b;

	scanf("%c%c", &c, &d);

	a = c - 48;
	b = d - 48;

	printf("a:%d\nb:%d\n", a, b);
	
	return 0;
}
