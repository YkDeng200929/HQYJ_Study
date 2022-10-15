#include <stdio.h>

int main()
{
	char buf[100] = {0};
	int i = 0;
	int len = sizeof(buf) / sizeof(buf[0]);

	scanf("%s", buf);
	
	for(i = 0; buf[i] != '\0'; i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	return 0;
}
