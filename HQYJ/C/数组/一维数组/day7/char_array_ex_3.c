#include <stdio.h>

int main()
{
	char buf[27];
	int i = 0;
	int len = sizeof(buf) / sizeof(buf[0]) - 1;
	char temp = 'A';

	for(i = 0; i < len; i++)
	{
		buf[i] = temp++;
	}
	buf[i] = '\0';
	printf("%s\n", buf);

	return 0;
}
