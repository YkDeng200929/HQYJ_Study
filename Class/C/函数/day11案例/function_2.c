#include <stdio.h>
//全局变量
//作用域：从定义全局变量开始，往后都可以使用
int x;
int y;

void Func_1()
{
	//局部变量
	int a;
	int c;

	a = 1;
	printf("y:%d\n", y);
	return ;
}

int main()
{
	//局部变量，未初始化的值是随机值
	int a = 10;
	int b[5];

	{
		int a = 20;
		//int c = 0;
		printf("a:%d\n", a);
	}
	
	printf("a:%d\n", a);

	Func_1();
	//printf("c:%d\n", c);

	return 0;
}



