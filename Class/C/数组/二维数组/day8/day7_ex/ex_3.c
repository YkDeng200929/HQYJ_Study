#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char buf1[100] = {0};
	char buf2[100] = {0};
	int data1 = 0;
	int data2 = 0;
	int len = 0, i = 0;

	gets(buf1);
	gets(buf2);

	len = strlen(buf1) + strlen(buf2);
	printf("len : %d\n", len);

	for(i = 0; '\0' != buf1[i]; i++)
	{
		data1 = data1 * 10 + ( buf1[i] - '0');
	}
	for(i = 0; '\0' != buf2[i]; i++)
	{
		data2 = data2 * 10 + ( buf2[i] - '0');
	}

	printf("data1 + data2 = %d\n", data1 + data2);

	
	return 0;
}
