#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void func1()
{
	printf("welcome to wuhan");
}

void func2()
{
	printf("welcome to hubei");
	//exit(EXIT_SUCCESS);//库函数，刷新缓存
	_exit(EXIT_SUCCESS);//系统调用，不刷新缓存
}
int main()
{
	func1();
	func2();

	return 0;
}
