#include <stdio.h>

int main()
{
	int data = 0;

	scanf("%d", &data);
#if 0
	data++;
	printf("ret :%d\n", 1 == (data % 2));
#else
	printf("ret :%d\n", 0 == (data++ % 2));
#endif
	return 0;
}
