#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main()
{
	DIR *dirp = NULL;//定义一个目录流指针
	struct dirent *entry;
	dirp = opendir("henry");//打开一个目录，返回目录流指针
	if(dirp == NULL)//出错处理
	{
		perror("open henry");
		return -1;
	}
	errno = 0;
	while(1)
	{
		entry = readdir(dirp);//读目录,返回下一个文件结构体首地址
		if(entry == NULL)
		{
			if(errno != 0)//判断是否有错误
			{
				perror("readdir");
				return -1;
			}else//读到末尾
			{
				printf("EOF\n");	
				break;
			}
		}
		printf("d_name %s\n",entry->d_name);
	}
	closedir(dirp);//关闭一个目录
	return 0;
}
