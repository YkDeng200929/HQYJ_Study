#include <stdio.h>
//int ret = 0;

/*
 *功能：获取两个数的加法运算
 *函数名：Func_my_add
 *参数：int x, int y
 *返回值：int *
 *other：指针函数 --> 本质上是一个函数，返回值是指针类型
 */
int *Func_my_add(int x, int y)
{
	//ret : 局部变量
	//static ret：静态局部变量
	static int ret;
	int *q = NULL;

	q = &ret;
	ret = x + y;

	return q;
}

int main()
{
	int a = 10, b = 20;
	int ret_m = 0;
	int *p = NULL;
	
	p = Func_my_add(a, b);
	printf("*p : %d\n", *p);

	ret_m = *(Func_my_add(a, b));
	printf("ret : %d\n", ret_m);
	
	return 0;
}

