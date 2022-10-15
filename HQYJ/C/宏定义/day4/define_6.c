#include <stdio.h>
#define M 0

int main()
{
#ifndef N
	printf("%d\n", __LINE__);
	printf("Not N\n");
#endif
	printf("%d\n", __LINE__);

	return 0;
}
