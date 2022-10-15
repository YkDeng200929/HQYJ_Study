#include <stdio.h>
#include <string.h>

int main()
{
	char *string1 = "1a2b3C4D";
	char buf[100];
	int i = 0, j = 0;
	int len = strlen(string1);

	for(i = 0, j = 0; i < len; i++)
	{
		if(string1[i] >= 'a' && string1[i] <= 'z' || (string1[i] >= 'A' && (string1[i]) <= 'Z'))
		{
			buf[j++] = string1[i];
		}
	}
	buf[j] = '\0';
	puts(buf);
	printf("buf_len:%ld\n", strlen(buf));



	return 0;
}
