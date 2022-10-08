#include <stdio.h>

// 该函数不会打印换行符号
void put1(const char *string)
{
	while (*string != '\0')
		putchar(*string++);
}

int main(void)
{
	char words[80] = "I love you forever";
	put1(words);

	return 0;
}
