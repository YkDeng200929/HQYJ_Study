#include <stdio.h>

int main()
{
	int i = 0;
	int data = 0;

	scanf("%d", &data);

	while(i < data)
	{
		i += 2;
		if(i < data)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
