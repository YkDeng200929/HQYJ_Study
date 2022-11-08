#include <stdio.h>

int main()
{
	char a = 0;

	scanf("%c", &a);

	if(a >= 'A' && a <= 'Z')//大写字母
	{
		//printf("%c\n", a + 32);
		printf("capital letter\n");
	}
	else if(a >= 'a' && a <= 'z')//小写字母
	{
		//printf("%c\n", a - 32);
		printf("small letter\n");
	}
	else if(a >= '0' && a <= '9')
	{
		printf("digit\n")
	}
	else//其他字符
	{
		//printf("%c\n", a);
		printf("other character\n");
	}

	return 0;
}
