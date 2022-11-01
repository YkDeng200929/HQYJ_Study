#include <stdio.h>

int main(int argc, const char *argv[])
{
	//定义变量
	int a;//a是一个随机值
	char b;

	long int len = 0;
	len = sizeof(long int);

	//printf("sizeof(long int) = %ld\n", sizeof(long int));
	printf("len : %ld\n", len);

	printf("sizeof(a) = %ld\n", sizeof(a));
	printf("sizeof(int) = %ld\n", sizeof(int));
	printf("sizeof(b) = %ld\n", sizeof(b));
	printf("sizeof(char) = %ld\n", sizeof(char));
	
	return 0;
}
