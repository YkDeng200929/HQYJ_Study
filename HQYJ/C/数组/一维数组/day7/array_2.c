#include <stdio.h>

int main()
{
	char a[5] = {'h', 'e', 'l', 'l', 'o'};

	//首元素的地址
	printf("&a[0] :%p\n", &a[0]);
	//a <==> &a[0]
	printf("a     :%p\n", a);
	//a + 1 <==> &a[0] + 1
	printf("a + 1 :%p\n", a + 1);

	//数组的地址
	printf("&a    :%p\n", &a);
	//a类型 char [5]
	//a + 1 --> 移动 char [5]
	printf("&a + 1:%p\n", &a + 1);
	

	return 0;
}
