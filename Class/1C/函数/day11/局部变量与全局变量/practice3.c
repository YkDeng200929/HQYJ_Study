#include <stdio.h>
// 求阶乘
int factorial(int num)
{
	int i,res=1;
	for (i=1; i<=num; i++)
		res*=i;
	return res;
}

// 判断润年
int do_leap(int y)
{
	if ((y%4 == 0) && (y%100 != 0) && (y%400 ==0))
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	printf("Enter:\n");
	scanf("%d", &n);
	printf("%d's n! = %d\n", n, factorial(n));

	int year, ret;
	printf("Enter a year:\n");
	scanf("%d", &year);
	if (ret = do_leap(year))

	return 0;
}
