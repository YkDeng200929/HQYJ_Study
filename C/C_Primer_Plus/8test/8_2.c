#include <stdio.h>
int main(void)
{
	char ch;
	while ((ch = getchar()) != '&')
	{
		putchar(ch);
		printf("%+10d\n", ch);
	}
	return 0;
	}
