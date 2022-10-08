#include <stdio.h>

int main(void)
{
	
	char *pi[5] = {
		"i love you forever!",
		"just do it!",
		"Everything will be ok!",
		"Practice makes perfect",
		"One more thing"
	};// 相当于二维数组

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", pi[i]);
	}
	
	return 0;
}
