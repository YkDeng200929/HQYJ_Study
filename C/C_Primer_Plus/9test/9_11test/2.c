#include <stdio.h>
void chline(char ch, int i, int j){
	int count,n;
	for (count = 0; count < i; count++)
	{
		printf("%c ", ch);
		for (n = 0; n < j-1; n++)
			printf("%c ", ch);
		putchar('\n');
	}
}

int main(void)
{
	printf("Enter the char you want:\n");
	char ch;
	scanf("%c", &ch);
	putchar('\n');
	printf("Enter the row:\n");
	int i;
	scanf("%d", &i);
	putchar('\n');
	printf("Enter the col:\n");
	int j;
	scanf("%d", &j);
	putchar('\n');
	chline(ch, i, j);

	return 0;
}


