#include <stdio.h>

int main()
{
	char buf[100] = {0};
	int space_num = 0;
	int i = 0;

	while(1)
	{
		gets(buf);
		puts(buf);

		//space_num = 0;
		for(i = 0, space_num = 0; buf[i] != '\0'; i++)
		{
			if(' ' == buf[i])
			{
				space_num++;
			}
		}
		if(5 == space_num)
		{
			printf("GAME OVER\n");
			break;
		}
	}

	return 0;
}
