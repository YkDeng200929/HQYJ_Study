#include <stdio.h>

int main()
{
	int *p;//随机值，非法地址
	int *q = NULL;//q里面是0，非法地址
	int a, b;

	p = &a;
	q = &b;

	p = q;//p --> b的地址

	//*p = 800;//段错误
	//*q = 100;//段错误

	return 0;
}
