#include <stdio.h>
#include <string.h>
int main()
{
	char *ret;
	char buf[128] = {0};

	while(1)
	{
		ret = fgets(buf,sizeof(buf),stdin);
		if(ret == NULL)
		{
			if(feof(stdin))//测试是否到达文件尾部
			{
				break;
			}else
			{
				return -1;
			}
		}
		buf[strlen(buf) - 1] = '\0';//去掉'\n',换成'\0'
		if(strncmp(buf,"quit",4) == 0)//如果输入的前4个字符为quit, 则退出
		{
			break;
		}
		fputs(buf,stdout);//写入标准输出流，输出到屏幕显示
		putchar('\n');
	}
	return 0;
}
