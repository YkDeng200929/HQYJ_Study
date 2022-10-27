#include <stdio.h>
#include <stdbool.h>

bool func(void)
{
	int in_val;
	scanf("%d", &in_val);
	if (in_val > 0)
		return true;
	else
		return false;
}

int main()
{
	if (func())
		printf("Positive\n");
	else
		printf("Negative\n");

	return 0;
}
