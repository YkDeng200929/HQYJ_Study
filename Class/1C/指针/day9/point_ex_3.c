#include <stdio.h>

int main()
{
	unsigned int data = 0x11223344;
	unsigned short *q = NULL;
	unsigned short t1 = 0;
	unsigned short t2 = 0;

	q = (unsigned short *)&data;
	t1 = *q;
	t2 = *(q + 1);

	printf("t1:%#x\tt2%#x\n", t1, t2);
	printf("sum:%#x\nsub:%#x\n", t1 + t2, t1 - t2);

	return 0;
}
