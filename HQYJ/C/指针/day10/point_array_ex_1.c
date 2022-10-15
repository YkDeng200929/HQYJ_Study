#include <stdio.h>

int main()
{
	char a1[] = "abcde";
	char a2[] = "HELLO";
	char *p_array[] = {a1, a2, NULL};
	int i = 0, j = 0;

	//获取p_array这个数组中的每一个元素
	for(i = 0; p_array[i] != NULL; i++)
	{
		//内存循环中，获取字符串中的每一个字符
		//p_array[i] --> 每一个元素
		//[] <==> *()
		//*(p_array[i] + j) <==> p_array[i][j]
		for(j = 0; p_array[i][j] != '\0'; j++)
		{
			if(p_array[i][j] >= 'a' && p_array[i][j] <= 'z')
			{
				p_array[i][j] -= 32;
			}
			else if(p_array[i][j] >= 'A' && p_array[i][j] <= 'Z')
			{
				p_array[i][j] += 32;
			}
		}
	}
	for(i = 0; p_array[i] != NULL; i++)
	{
		puts(p_array[i]);
	}

	return 0;
}
