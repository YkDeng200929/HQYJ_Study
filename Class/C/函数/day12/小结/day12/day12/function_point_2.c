#include <stdio.h>

//定义 = 类型 + 名字
//类型 ： int (int x, int y)
int Func_add(int x, int y)
{
	return x + y;
}

int main()
{
	//定义3个函数指针
	int (*p)(int x, int y) = NULL;//--> 定义一个指针p，指向的是int (int x, int y)的函数
	int (*q)(int , int) = NULL;
	int (*e)() = NULL;

	p = Func_add;
	q = &Func_add;
	e = Func_add;

	printf("p:%d\n", p(10, 20));
	printf("q:%d\n", (*q)(20, 30));
	printf("e:%d\n", p(30, 40));


	return 0;
}
