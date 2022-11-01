#include <stdio.h>

int main()
{
	//定义 = 类型 + 名字
	//类型 = 定义 - 名字
	int a[5] = {10, 20, 30, 40, 50};
	int len = 0;

	printf("a[0] : %ld\n", sizeof(a[0]));
	//printf("a[0] : %ld\n", sizeof(int));
	//a --> int [5] --> 5 * 4
	printf("a    : %ld\n", sizeof(a));

	len = sizeof(a) / sizeof(a[0]);

	printf("len : %d\n", len);


	return 0;
}
