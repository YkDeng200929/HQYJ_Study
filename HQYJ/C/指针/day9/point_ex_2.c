#include <stdio.h>

int main()
{
	unsigned int reg = 0x12345678;
	unsigned int sum = 0;
	int i = 0;
	unsigned char *p = NULL;

	p = (unsigned char *)&reg;

	for(i = 0; i < 4; i++)
	{
		printf("%#x ", *(p + i));
		sum += *(p + i);
	}
	printf("\nsum:%#x\n", sum);

	return 0;
}
