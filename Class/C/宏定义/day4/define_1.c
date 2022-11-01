#include <stdio.h>

int main()
{
	printf("LINE:%d\n", __LINE__);
	printf("FILE:%s\n", __FILE__);
	printf("DATE:%s\n", __DATE__);
	printf("TIME:%s\n", __TIME__);
	
	return 0;
}
