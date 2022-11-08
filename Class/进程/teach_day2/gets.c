#include <stdio.h>

int main()
{
	char buf[8] = {0};

	gets(buf);
	printf("buf: %s\n", buf);
}
