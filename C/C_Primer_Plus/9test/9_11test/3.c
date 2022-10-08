#include <stdio.h>
void haha(char n, int count, int row){
	int m,z;
	for (m = 0; m < row; m++)
	{
		printf("%c", n);
		for (z = 0; z < count-1; z++)
			printf("%c", n);
		putchar('\n');
	}
}

int main(void)
{
	char ch;
	int count,row;
	printf("Enter char:\n");
	scanf("%c", &ch);
	printf("Enter the count and row:\n");
	scanf("%d %d", &count, &row);
	haha(ch, count, row);

	return 0;
}

