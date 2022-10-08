#include <stdio.h>

int main(void)
{
	int arr[5] = {1,2,3,4,5};

	printf("size of arr[5] is %ld\n", sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}
