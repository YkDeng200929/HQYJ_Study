#include <stdio.h>

int main()
{
	//一级指针保存 普通变量的地址
	int a = 10;
	int *p = &a;
	//二级指针保存 一级指针的地址
	//p --> int *
	//&p --> int **
	int **q =  &p;//q是二级指针，保存一级指针p的地址

	*p = 20;//对a赋值
	//*q --> p
	//**q --> *p --> a
	**q = 30;//对a赋值

	return 0;
}
