#include <stdio.h>

int main()
{
	int i = 0;

	for(i = 1; i < 10; i ++)
	{
		/*
		if(0 == i % 5)
		{
			//破坏离他最近的整个循环
			//break;
			//结束离他最近的本轮循环，进入下一轮循环
			continue;
			
		}
		else
		{
			printf("%d\n", i);
		}
		*/
		printf("hello\n");
		continue;
		printf("world\n");
	}

	return 0;
}
