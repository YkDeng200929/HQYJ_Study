#include <stdio.h>

void do_sum(void)
{
	int m, res;
	printf("请输入一个整数:\n");
	scanf("%d", &m);
	if (m%2 == 1)
	{
		for (int i=1; i <= m; i+=2)
		{
			res += i;
		}
	}
	else
	{
		for (int i=0; i <= m; i+=2)
		{
			res += i;
		}
	}
	printf("%d\n", res);
}

int num(int num)
{
	return num*num*num;
}

void do_flower()
{
	printf("以下打印水仙花数:\n");
	for (int i=100; i<=999; i++)
	{
		if (num(i/100)+num(i%100/10)+num(i%10) == i)
			printf("%d\n", i);
	}
}

int main()
{
	do_sum();
	do_flower();

	return 0;

}
