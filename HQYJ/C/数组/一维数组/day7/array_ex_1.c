#include <stdio.h>

int main()
{
	int a[8] = {10, 15, 27, 33, 78, 65};
	int i = 0;
	int len = sizeof(a) / sizeof(a[0]);
	int ret = 0, sum = 0, ave = 0;

	for(i = 0; i < len; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
		//判断是否为奇数
		if(0 != a[i] % 2)
		{
			ret += a[i];
		}
		sum += a[i];
	}
	ave = sum / len;
	printf("sum:%d\nave:%d\n", ret, ave);

	return 0;
}
