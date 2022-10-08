#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int num_blank = 0, num_return = 0, num_other = 0, final;

	printf("Enter: \n");
	while ((ch = getchar()) != STOP)
	{
		num_other++;

		if (ch == ' ')
		{
			num_blank++;
		}
		else if (ch == '\n')
		{
			num_return++;
		}

	}
	
	final = num_other - num_blank - num_return;


	printf("The number of blank is: %d\nThe number of return is: %d\nThe number of other character is:%d\n",
		       	num_blank, num_return, final);

	return 0;
}




