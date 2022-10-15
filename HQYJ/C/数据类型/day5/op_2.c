#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int ret = 0;

	//==全等于：两边相同为真
	//          两边不同位假(0)
	a = 10;
	ret = (10 == b);
	//!=不等于：两边相同为假(0)
	//          两边不相同为真
	ret = (10 != b);

	//> < >= <=

	printf("ret:%d\n", ret);

	return 0;
}
