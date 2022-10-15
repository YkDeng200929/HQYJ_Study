#include <stdio.h>

int main()
{
	int i = 0;
	int sum = 0;
	
	//1、i = 1
	//2、i <= 10 --> T --> 循环体
	//3、i++ --> i = 2
	//4、i <= 10 --> T --> 循环体
	//重复3，4
	//直到i <= 10 --> 假 --> 结束循环
	for(i = 1; i <= 10; i++)
	{
		//循环体
		sum += i;//sum = sum + i;
	}
	printf("sum :%d\n", sum);

	return 0;
}
