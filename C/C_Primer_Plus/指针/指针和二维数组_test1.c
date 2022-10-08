#include <stdio.h>

int main(void)
{
	int arr[4][5] = {0} ;

	printf("sizeof int: %d\n", sizeof(int));
	printf("arr: %p\n", arr);
	printf("arr + 1: %p\n", arr + 1);

	return 0;
}
