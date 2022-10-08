#include <stdio.h>
#include <string.h>
#define SIZE 80
char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;

}

int main(void)
{
	char flowers[SIZE];
	char addon[] = "s smell like old shoes";

	puts("What is your favorite flower?");
	if (s_gets(flowers, SIZE))
	{
		strcat(flowers, addon);// 衔接两个字符串
		puts(flowers);
		puts(addon);
	}
	else
		puts("End of file encountered!");
	puts("bye");
	
	return 0;
}


