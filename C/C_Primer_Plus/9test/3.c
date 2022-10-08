#include <stdio.h>
void print_ch(char ch, int count, int row)
{
	int r, num;
	for (r = 0; r < row; r++)
	{
		for (num = 0; num < count; num++)
			printf("%c", ch);
		putchar('\n');
	}

}
int main(void)
{
	printf("Enter the char you want:\n");
	char ch;
	scanf("%c", &ch);
	putchar('\n');

	printf("Enter the number of char you want:\n");
	int count;
	scanf("%d", &count);
	putchar('\n');

	printf("Enter the row you want:\n");
	int row;
	scanf("%d", &row);
	putchar('\n');

	print_ch(ch, count, row);

	return 0;
}

