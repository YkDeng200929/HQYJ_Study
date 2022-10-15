#include <stdio.h>

int main()
{
	char a = 0x13, b = 0x78;

#if 1
	a = a + b;
	b = a - b;
	a = a - b;
#else
	a = a ^ b;
	//printf("a:%#x\tb:%#x\n", a, b);
	b = a ^ b;
	//printf("a:%#x\tb:%#x\n", a, b);
	a = a ^ b;
	//printf("a:%#x\tb:%#x\n", a, b);
#endif
	printf("a:%#x\tb:%#x\n", a, b);

	return 0;
}
