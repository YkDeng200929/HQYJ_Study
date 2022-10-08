#include <stdio.h>
#define NUM 10
int main(void)
{
	int n, i;

	printf("Enter\n");
	scanf("%d", &n);
	getchar();

	char a[n+1];

	printf("Please enter:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%c", &a[i]);
	}

	a[n] = '\0';

	printf("You enter is %s", a);

	return 0;

}

