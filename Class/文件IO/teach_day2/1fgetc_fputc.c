#include <stdio.h>

void read_file(FILE *fp)
{
	int val;
	
	while(1)
	{
		val = fgetc(fp);//从fp对应的文件中读1个字符
		if(val == EOF)
		{
			break;
		}
		fputc(val, stdout);//向标准输出流写入1个字符，显示到终端屏幕上
	}
}

int main()
{
	FILE *fp;

	fp = fopen("file","r");//以只读方式打开file文件，返回fp流指针
	if(fp == NULL)
	{
		perror("file");
		return -1;
	}
	
	read_file(fp);
	fclose(fp);
	return 0;
}
