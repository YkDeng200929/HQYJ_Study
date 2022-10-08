#include <stdio.h>
int main(void)
{
	int count = 0;
	char ch;
	printf("Enter: \n");
	
	while (getchar() != '&')	
	{
		count++;
	}
	
	printf("The number of you enter is %d\n", count);

	return 0;
}

