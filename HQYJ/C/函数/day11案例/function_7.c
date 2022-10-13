#include <stdio.h>

//功能：打印一维数组
void Func_printf_array(int *q, int len)
{
	int i = 0;

	for(i = 0; i < len; i++)
	{
		printf("%d ", q[i]);
	}
	putchar('\n');
	
	return ;
}

int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int len = sizeof(a) / sizeof(a[0]);

	Func_printf_array(a, len);

	return 0;
}
