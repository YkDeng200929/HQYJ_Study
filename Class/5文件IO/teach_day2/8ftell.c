#include <stdio.h>

int main()
{
	FILE *fp;
	long int ret;
	fp = fopen("file","r+");
	if(fp == NULL)
	{
		perror("");
		return -1;
	}
	
	fseek(fp,0,SEEK_END);//将文件指针定位到文件末尾
	ret = ftell(fp);//通过ftell函数得到从文件开头到当前文件指针位置的偏移量
	printf("file size: = %ld\n",ret);//这里获得了文件大小

	return 0;
}
