#include <stdio.h>

int main()
{
	unsigned char a = 0x13;
	unsigned char b = 0x78;

	printf("&:%#x\n", a & b);
	printf("|:%#x\n", a | b);
	printf("^:%#x\n", a ^ b);
	printf("~a:%#x\n", ~a);
	printf("~b:%#x\n", ~b);

	printf("5 << 1  :%d\n", 5 << 1);
	printf("-5 << 1 :%d\n", -5 << 1);
	//0000 0101 >> 2 --> 0000 0001 --> 1
	printf("5 >> 1  :%d\n", 5 >> 1);
	//原码：1000 0101
	//补码：1111 1011
	//1111 1011 >> 2 --> 1111 1110
	//补码：1111 1110
	//原码：1000 0010 --> -2
	printf("-5 >> 2 :%d\n", -5 >> 2);

	return 0;
}
