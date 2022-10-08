#include <stdio.h>

// 为put添加计算字符个数的小功能
int put2(const char *string)
{
	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');

	return count;
}

int main(void)
{
	printf("The total char in put2() function is %d\n", puts("This is the argument in put2()"));

	return 0;
}
