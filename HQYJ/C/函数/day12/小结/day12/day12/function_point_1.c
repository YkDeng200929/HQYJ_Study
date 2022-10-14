#include <stdio.h>

//定义 = 类型 + 名字
//类型 ： int (int x, int y)
int Func_add(int x, int y)
{
	return x + y;
}

int main()
{
	int ret = 0;
	//函数指针 --> 本质上是一个指针，指向的是一个函数
	//int (int x, int y) --> 目标类型
	//int (*)(int x, int y) --> 指针类型
	int (*p)(int x, int y) = NULL;//--> 定义一个指针p，指向的是int (int x, int y)的函数
/*
	//Func_add 理解为 函数名
	p = &Func_add;
	//调用
	ret = (*p)(10, 20);
*/
	//Func_add 理解为 函数入口地址
	p = Func_add;
	//调用
	ret = p(10, 20);

	printf("ret : %d\n", ret);

	return 0;
}
