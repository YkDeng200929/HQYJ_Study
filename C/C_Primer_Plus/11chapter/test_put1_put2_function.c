#include <stdio.h>

void put1(const char *string)
{
	while (*string)
		putchar(*string++);// ++ 高于 *，读到空字符时值为０，也就是false，退出循环
}

int put2(const char *string)
{
	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
}

int main(void)
{
	put1("If I'd as much money");
	put1(" as I could spend,\n");
	printf("I count %d characters.\n", put2("I never would cry old chairs to mend"));

	return 0;
}

