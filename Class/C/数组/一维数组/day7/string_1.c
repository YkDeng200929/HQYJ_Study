#include <stdio.h>
#include <string.h>

int main()
{
	char buf[100];
	int len = 0;

	gets(buf);
	//fgets(buf, 7, stdin);

	puts(buf);

	len = strlen(buf);
	printf("len:%d\n", len);

	return 0;
}
