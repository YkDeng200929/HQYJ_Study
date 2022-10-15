#include <stdio.h>

int main()
{
	//定义指针变量
	//1、指针类型
	//   1>目标数据类型
	//   2>加上 *
	//2、加上变量名
	int *p_a;//指向目标类型为int的指针
	int a = 10;

	//*p_a <==> a
	p_a = &a;

	printf("p_a :%p\n", p_a);
	printf("&a  :%p\n", &a);
	
	//a = 20;
	*p_a = 30;//a = 30
	printf("a   :%d\n", a);
	printf("*p_a:%d\n", *p_a);

	return 0;
}
