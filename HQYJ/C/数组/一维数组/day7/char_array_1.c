#include <stdio.h>

int main()
{
	//数组a是字符数组
	//定义字符数组
	char a[] = {'h', 'e', 'l', 'l', 'o'};
	//buf是字符串
	//定义字符串
	char buf[] = "hello";
	int i = 0;

	//数组的输出
	for(i = 0; i < sizeof(a)/ sizeof(a[0]); i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");

	return 0;
}
