#include <stdio.h>

int main()
{
	int i, j, q;

	for(i = 1; i < 5; i++)
	{
		for(j = 1; j < 5; j++)
		{
			for(q = 1; q < 5; q++)
			{
				if(i != j && i != q && j != q)
				{
					printf("%d\n", i * 100 + j * 10 + q);
				}
			}
		}
	}

	return 0;
}
