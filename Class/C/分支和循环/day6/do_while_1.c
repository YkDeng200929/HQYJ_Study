#include <stdio.h>

int main()
{
	int pw = 0;
	int flag = 0;
	
	do
	{
		if(0 == flag)
		{
			printf("input password:");
			scanf("%d", &pw);
			flag++;
		}
		else
		{
			printf("pw error input again:");
			scanf("%d", &pw);
			flag++;
		}
	}while(pw != 123456 && flag < 3);
	
	if(123456 == pw)
	{
		printf("welcome\n");
	}
	else
	{
		printf("GAME OVER\n");
	}


	return 0;
}
