#include <stdio.h>

//值传参:在函数体内，对形参作任何操作，不影响实参
int Func_add(int x, int y)
{
	//10 20
	printf("x:%d\ty:%d\n", x, y);
	x = 30;
	y = 40;
	//30 40
	printf("x:%d\ty:%d\n", x, y);

	return x + y;
}

int main()
{
	int a = 10, b = 20;

	//10 20
	printf("line:%d\ta:%d\tb:%d\n", __LINE__, a, b);
	Func_add(a, b);
	//
	printf("line:%d\ta:%d\tb:%d\n", __LINE__, a, b);

	return 0;
}
