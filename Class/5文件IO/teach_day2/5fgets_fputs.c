#include <stdio.h>
#include <string.h>

int copy_file(FILE *fp1,FILE *fp2)//拷贝文件
{
	char *ret;
	char buf[64] = {0};

	while(1)
	{
		ret = fgets(buf,sizeof(buf),fp1);//按行从fp1对应的文件中读1行字符到buf中
		if(ret == NULL)
		{
			if(feof(fp1))//读到文件末尾返回0
			{
				return 0;
			}else//出现错误，拷贝失败打印一句话
			{
				fprintf(stderr,"fgets fail\n");
				return -1;
			}
		}
		fputs(buf,fp2);//写入到fp2对应的文件中
	}


}
int main()
{
	int ret;
	FILE *fp1,*fp2;

	fp1 = fopen("file","r");//只读方式打开
	if(fp1 == NULL)
	{
		perror("file");
		return -1;
	}

	fp2 = fopen("copy","w+");//读写方式打开，文件不存在则创建
	if(fp2 == NULL)
	{
		perror("copy");
		return -1;
	}
	
	ret = copy_file(fp1, fp2);
	if(ret == 0)
	{
		printf("copy success\n");
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
