// 使用静态局部变量
#include <stdio.h>

void trystat(void)
{
	int fade = 1;// fade在每次调用该函数时会初始化一次
	static int stay = 1;// stay为局部静态变量，除了编译时会初始化一次外，它的值不会被初始化

	printf("fade = %d and stay = %d\n", fade++, stay++);

}

int main(void)
{
	int count;

	for (count = 1; count <= 3; count++)
	{
		printf("here comes iteration %d: \n", count);
		trystat();
	}

	return 0;
}
