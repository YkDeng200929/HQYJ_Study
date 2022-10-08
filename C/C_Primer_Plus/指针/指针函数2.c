#include <stdio.h>

char *getWord(char c) //　返回值为字符串地址(使用指针变量作为函数的返回值，就是指针函数)
{
	char str1[] = "Apple";
	char str2[] = "Banana";
	char str3[] = "Cat";
	char str4[] = "Dog";
	char str5[] = "None";

	switch(c)
	{
		case 'A': return str1;
		case 'B': return str2;
		case 'C': return str3;
		case 'D': return str4;
		default: return str5;
	}

}

int main(void)
{
	char input;

	printf("请输入一个字符串:\n");
	scanf("%c", &input);

	printf("%s\n", getWord(input));

	return 0;
}
