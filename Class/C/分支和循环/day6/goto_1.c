#include <stdio.h>

int main()
{
	//假：0
	while(0)
	{
		goto flag;
	}
	printf("hello\n");
flag:
	printf("line:%d\n", __LINE__);

	return 0;
}
