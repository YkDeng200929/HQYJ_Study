#include <stdio.h>
#define SIZE 5
int main(void)
{
	int days[SIZE] = {31, 28, 3, 4, 5};
	int index;
	
	for (index = 0; index < SIZE; index++)
		printf("this is the %d number: %d\n", index+1, *(days + index));

	return 0;
}
