#include <stdio.h>

int main()
{
	int data1 = 0, data2 = 0;
	int *p = NULL;
	int *q = NULL;
	int temp = 0;

	p = &data1;
	q = &data2;

	scanf("%d%d", p, q);
	printf("data1:%d\tdata2:%d\n", data1, data2);

	temp = *p;
	*p = *q;
	*q = temp;

	printf("data1:%d\tdata2:%d\n", data1, data2);

	return 0;
}
