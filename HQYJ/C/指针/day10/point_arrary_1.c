#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	//指针数组可以理解为(int *) buf[5]
	//int * --> 指针类型
	//buf[5] --> 数组 
	int *buf[5];

	buf[0] = &a;
	buf[1] = &b;

	*buf[0] = 10;//a
	*buf[1] = 20;//b

	printf("a:%d\n", a);
	printf("b:%d\n", b);

	//获取整个数组的大小
	printf("整个数组 : %ld\n", sizeof(buf));
	//获取单个元素的大小
	printf("单个元素 : %ld\n", sizeof(buf[0]));
	//获取元素个数
	printf("元素个数 : %ld\n", sizeof(buf) / sizeof(buf[0]));
	

	return 0;
}
