#include <stdio.h>

int main()
{
	char a = 0;

	scanf("%c", &a);

	//2<=x<=7//error
	//x >= 2 && x <= 7
	printf("ret : %d\n", !(a >= 'A' && a <= 'Z'));

	return 0;
}
