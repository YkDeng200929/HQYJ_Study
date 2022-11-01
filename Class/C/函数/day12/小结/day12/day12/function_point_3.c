#include <stdio.h>
//定义新的类型
//P_ADD -类型-> int (*)(int x, int y)
typedef int (*P_ADD)(int x, int y);

//int (*)(int x, int y)
//int (*)(int , int)
//int (*)()
//
int Func_add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 9, b = 5;
	//定义 = 类型 + 名字
	P_ADD p = NULL;//定义一个变量名为p的变量，p的类型是P_ADD类型，int (*)(int x, int y)
	
	p = Func_add;
	printf("ret:%d\n", p(a, b));


	return 0;
}
