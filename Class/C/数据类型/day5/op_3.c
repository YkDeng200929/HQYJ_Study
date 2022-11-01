#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 5;

	//a > b 为 假
	//a < b 为 真
	//printf("ret : %d\n", !(a > b || a < b));
	printf("ret : %d\n", !(a > b) && a < b);

	//三目运算符，条件运算符
	//求两个数的大小
	printf("ret : %d\n", a > c ? a : c);

	return 0;
}
