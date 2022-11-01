#include <stdio.h>

//x = a --> 把实参赋值给形参
//y = b --> 把实参赋值给形参
int Func_add(int x, int y)
{
	printf("X;%d\ny:%d\n", x, y);

	return x + y;
}

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);

	Func_add(a, b);

	return 0;
}
