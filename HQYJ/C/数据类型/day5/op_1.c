#include <stdio.h>

int main()
{
	int a = 10;
	int b = 3;
	int ret = 0;	
	//%两边都是整数
	//printf("ret: %d\n", a%b);
	//++ --
	//后置:先赋值，再自增(减)
	//ret = a++;//ret = a; a = a + 2
	//printf("ret:%d\na:%d\n", ret, a);
	//ret = b--;//ret = b; b = b - 1
	//printf("ret:%d\nb:%d\n", ret, b);
	//前置
	ret = ++a;//a = a + 1; ret = a;
	printf("ret:%d\na:%d\n", ret, a);
	ret = --b;//b = b - 1; ret = b
	printf("ret:%d\nb:%d\n", ret, b);
	

	return 0;
}
