#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
	ssize_t ret;
	char buf[32] = {0};

	while(1)
	{
		memset(buf,0,sizeof(buf));
		ret = read(0,buf,sizeof(buf));//尝试从标准输入读sizeof(buf)个字节到buf中	
		if(ret == -1)//出现错误
		{
			perror("read");
			return -1;
		}else if(ret == 0)//读到文件末尾
		{
			printf("EOF\n");
			break;
		}
		if(strncmp(buf,"quit",4) == 0)//输入quit时退出
		{
			break;
		}
		buf[strlen(buf) - 1] = '\0';//'\n'变成'\0'
		printf("buf: %s\n",buf);
	}
	return 0;
}
