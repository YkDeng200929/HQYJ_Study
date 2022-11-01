#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	int ret = 0, sum = 0;

	scanf("%d", &i);

	for(j = 0; j < i - 1; j++)
	{
		ret = ret * 10 + 3;
		printf("%d + ", ret);
		sum += ret;
	}
	//最后一次加的值
	printf("%d\n", ret * 10 + 3);
	sum += (ret * 10 + 3);
	printf("sum:%d\n", sum);

	return 0;
}
