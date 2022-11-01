#include <stdio.h>

int main()
{
	//函数的学习
	//1、man手册-->函数原型
	//2、函数名
	//3、参数
	//4、返回值
	//5、功能
	char a;
	int a_1 = 321;//--> 65 

	a = getchar();

	putchar(a);
	putchar('\n');
	//会把int类型转换成unsigned char
	putchar(a_1);
	putchar('\n');

	return 0;
}
