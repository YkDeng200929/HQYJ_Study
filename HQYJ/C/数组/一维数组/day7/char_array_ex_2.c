#include <stdio.h>

int main()
{
	char buf[] = {"anihc evol l"};
	int i = 0;
	int len = sizeof(buf) / sizeof(buf[0]);
	char temp = 0;

	for(i = 0; i < (len / 2); i++)
	{
		temp = buf[i];
		buf[i] = buf[len - 1 - 1 - i];
		buf[len - 1 - 1 - i] = temp;
	}
	printf("%s\n", buf);


	return 0;
}
