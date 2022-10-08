#include <stdio.h>

char *getWord(char c) //　返回值为字符串地址
// (使用指针变量作为函数的返回值，就是指针函数)
{
	switch(c)
	{
		case 'A': return "Apple";
		case 'B': return "Banana";
		case 'C': return "Cat";
		case 'D': return "Dog";
		default: return "None";
		// 返回的不是字符串，而是字符串的首元素地址
	}

}
// 解释 *getWord(char c):
// getWord 通过字符参数，寻找到了对应的case，然后返回值为对应return字符串的首元素地址，最后通过*解引用地址，得到对应的字符串
//
// (char *) 返回char类型的指针
int main(void)
{
	char input;

	printf("请输入一个字符串:\n");
	scanf("%c", &input);

	printf("%s\n", getWord(input));

	return 0;
}
