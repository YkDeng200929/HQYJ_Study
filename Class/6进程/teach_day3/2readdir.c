#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

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
	entry = readdir(dirp);//读目录,返回下一个文件结构体首地址
	printf("d_name %s\n",entry->d_name);

	closedir(dirp);//关闭一个目录
	return 0;
}
