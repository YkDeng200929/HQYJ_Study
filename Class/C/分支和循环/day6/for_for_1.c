#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	//控制行数
	for(i = 0; i < 10; i++)
	{
		//控制列数
		for(j = 0; j < 10; j++)
		{
			if(j <= i)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
