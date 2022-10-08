#include <stdio.h>

int fin_num2(int num1, int num2)
{
	int count = 0;
	for (int i = num1; i <= num2; i++)
	{
		if (i < 20)
		{
			if ((i % 10 == 2))
				count++;
		}
		else if (i < 30)
		{
			if (i == 22)
				count += 2;
			else
				count++;
		}
		else if (i % 10 == 2)
			count++;
	}
	return count;
}

int main(void)
{
	printf("输入:\n");

	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("%d\n", fin_num2(num1, num2));

	return 0;
}
