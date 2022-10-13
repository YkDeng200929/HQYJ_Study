#include <stdio.h>
//静态全局变量：未初始化，默认值为0，只初始化1次
static int d;
//全局变量:未初始化，默认值为0
int x;

void Func_1()
{
	static int b;
	int c = 0;

	b++;
	c++;

	printf("b:%d\n", b);
	printf("c:%d\n", c);
	return ;
}
int main()
{
	//静态局部变量:未初始化，默认值为0
	static int a;

	//printf("a:%d\n", a);
	Func_1();
	printf("----------\n");
	Func_1();

	return 0;
}
