#include <stdio.h>

int main()
{
	int num = 0;
	int data = 0;

	scanf("%d", &num);
#if 0
	if(num >= 0 && num < 60)
	{
		printf("E\n");
	}
	else if(num >= 60 && num < 70)
	{
		printf("D\n");
	}
	else if(num >= 70 && num < 80)
	{
		printf("C\n");
	}
	else if(num >= 80 && num < 90)
	{
		printf("B\n");
	}
	else if(num >= 90 && num <= 100)
	{
		printf("A\n");
	}
	else
	{
		printf("error\n");
	}
#else
	//第一种
	/*
	if(num < 0 || num > 100)
	{
		printf("error\n");
		return 0;
	}
	*/
	//第二种
	data = num / 10;
	switch(data)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		if(num < 0)
		{
			printf("error\n");
			break;
		}
		printf("E\n");
		break;
	case 6:
		printf("D\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 9:
	case 10:
		if(num > 100)
		{
			printf("error\n");
			break;
		}
		printf("A\n");
		break;
	default:
		printf("error\n");
		break;
	}
#endif

	return 0;
}
