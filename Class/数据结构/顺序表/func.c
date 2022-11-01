#include <stdio.h>

int func(void)
{
	int in_val;
	scanf("%d", &in_val);
	if (in_val > 0)
		return 1;
	else
		return 0;
}

int main()
{
	int val;
	val = func();
	if (val >= 1)
		printf("Positive\n");
	else
		printf("Negative\n");

	return 0;
}
