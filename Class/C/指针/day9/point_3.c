#include <stdio.h>

int main()
{
	int a = 0x12345678;
	int *p_int = &a;
	char *p_char = NULL;
	short *p_short = (short *)&a;

	//p_char --> char *
	//(char *)&a --> char *
	p_char = (char *)&a;

	printf("*p_int : %#x\n", *p_int);
	printf("*p_char: %#x\n", *p_char);
	printf("*p_short:%#x\n", *p_short);
	printf("----------------------------\n");

	printf("&a          :%p\n", &a);
	printf("p_char + 1  :%p\n", p_char + 1);
	printf("p_short + 1 :%p\n", p_short + 1);
	printf("p_int + 1   :%p\n", p_int + 1);



	return 0;
}
