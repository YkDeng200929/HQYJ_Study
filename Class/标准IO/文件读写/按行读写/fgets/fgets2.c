#include <stdio.h>

int main(void)
{
	char str[9];

	fgets(str, 4, stdin);
	printf("%s", str);

	return 0;
}
