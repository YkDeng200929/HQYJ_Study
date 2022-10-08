#include <stdio.h>
#include <string.h>  // 提供strcmp(), strchr()原型
#include <stdbool.h> //　c99特性

char *s_gets(char *st, int n);

enum spectrum {red, orange, yellow, green, blue, violet};
const char *colors[] = {"red", "orange", "yellow",
	"green", "blue", "violet"};
#define LEN 30

int main(void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;

	puts("Enter a color (empty line to quite):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\n')
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}

		if (color_is_found)
			switch (color)
			{
				case red: puts("Rose are red."); break;
				case orange: puts("Poppies are orange."); break;
				case yellow: puts("Sunflowers are yellow."); break;
				case green: puts("Grass is green."); break;
				case blue: puts("Bubells are blue"); break;
				case violet: puts("Violets are violets"); break;
			}
		else
			printf("I don't know about the color %s.\n", choice);
		color_is_found = false;
		puts("Next color, please (empty line to quite)");
	}
	puts("Goodbye!");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');          // 查找换行符 
		if (find)                         // 如果地址不是NULL
			*find = '\0';             // 在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue;         // 清理输入行
	}
	return ret_val;
}
