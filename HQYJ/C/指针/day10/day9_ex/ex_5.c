#include <stdio.h>
#include <string.h>

int main()
{
	char a[] = "hello";
	char *p = &a[0];
	char **q = &p;
	int i = 0;

	for(i = 0; p[i] != '\0'; i++)
	//for(i = 0; i < strlen(a); i++)
	{
		//printf("%c ", p[i]);
		//printf("%c ", *(p + i));
		printf("%c ", (*q)[i]);
		printf("%d \n", *(*q + i));
	}
	putchar('\n');

	return 0;
}
