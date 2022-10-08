#include <stdio.h>
#define STLEN 81
int main(void)
{
	char words[STLEN];
	
	puts("Enter a string:");
	gets(words);// 如果输入的字符串超过了81，那么gets会无法检测而导致缓冲区溢出
	printf("your string twice:\n");
	printf("%s\n", words);
	puts(words);

	return 0;
}
