#include <stdio.h>
#include <string.h>

int main()
{
	char dest_buf[100] = "hello12345";
	char src_buf[100] = "world";
	char buf_1[100] = "hello1";
	char buf_2[100] = "hello";
	int len = 0, i = 0;
	int ret = 0;
	//字符串比较
	ret = strcmp(buf_1, buf_2);
	if(0 == ret)
	{
		printf("buf_1 = buf_2\n");
	}
	else if(ret > 0)
	{
		printf("buf_1 > buf_2\n");
	}
	else
	{
		printf("buf_1 < buf_2\n");
	}

	//字符串拷贝
	strcpy(dest_buf, "world");
	len = strlen(dest_buf);
	printf("len :%d\n", len);

	for(i = len + 1; dest_buf[i] != '\0'; i++)
	{
		printf("%c", dest_buf[i]);
	}
	putchar('\n');
	//字符串追加
	strcat(dest_buf, src_buf);
	strcat(dest_buf, " world");
	puts(dest_buf);

	return 0;
}
