#include <stdio.h>

int main()
{
	unsigned char data = 0x78;

	data = data & ~(1 << 5);
	printf("%#x\n", data);

	return 0;
}
