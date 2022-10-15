#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char buf1[100] = {0};
	char temp_buf[100] = {0};
	char a = 0, temp = 0;
	int  i = 0, j = 0;
	int n;

	//scanf("%s", buf1);
	fgets(buf1, 99, stdin);
	scanf("%d", &n);
	scanf("%c", &a);
	
	//n -= '0';
	//1 --> 下标：0
	for(i = (n - 1), j = 0;'\0' !=  buf1[i]; i++, j++)
	{
		temp_buf[j] = buf1[i];
	}
	buf1[n - 1] = a;
	buf1[n] = '\0';
	strcat(buf1, temp_buf);

	puts(buf1);
	
	return 0;
}
