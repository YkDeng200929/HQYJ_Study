#include <stdio.h>
#define MSG "I am a symbolic string constant"
#define MAXLENGTH 81

int main(void)
{
	char words[MAXLENGTH] = "I am a string in an arry";
	const char *pt1 = "Something is pointing at me";

	printf("words[0] = %c; *(pt1+1) = %s\n", words[0], *(pt1+1));

	// puts() 会自动输出一个换行符
	// puts 函数只显示字符串
	puts("Here are some strings:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);

	return 0;
}
