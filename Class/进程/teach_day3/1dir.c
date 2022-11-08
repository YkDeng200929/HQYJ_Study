#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	DIR *dirp = NULL;//定义一个目录流指针

	dirp = opendir("henry");//打开一个目录，返回目录流指针
	if(dirp == NULL)//出错处理
	{
		perror("open henry");
		return -1;
	}

	closedir(dirp);//关闭一个目录
	return 0;
}
