#include <stdio.h>

int main()
{
	char str[100];
	char *p_max = NULL;
	char *p_min = NULL;
	int i = 0;
	char temp;

	gets(str);
	p_max = str;
	p_min = str;
	for(i = 0; i < strlen(str); i++)
	{
		if(*p_max < str[i])
		{
			p_max = &str[i];
		}
		if(*p_min > str[i])
		{
			p_min = &str[i];
		}
	}

	temp = *p_min;
	*p_min = *p_max;
	*p_max = temp;

	puts(str);

	return 0;
}
