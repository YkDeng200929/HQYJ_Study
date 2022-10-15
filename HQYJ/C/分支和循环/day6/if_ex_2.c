#include <stdio.h>

int main()
{
	int year = 0;
	
	scanf("%d", &year);

	if((0 == year % 4 && year % 100 != 0) || (0 == year % 400))
	{
		printf("%d year is leap year\n", year);
	}
	else
	{
		printf("%d year is not leap year\n", year);
	}

	return 0;
}
