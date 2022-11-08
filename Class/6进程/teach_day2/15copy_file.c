#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void copy_file(int fd1, int fd2)//把2个文件描述符传过来
{
	ssize_t ret;
	char buf[32] = {0};

	while(1)
	{
		memset(buf,0,sizeof(buf));//每次读文件前buf清0
		ret = read(fd1,buf,sizeof(buf));//尝试读取sizeof(buf)个字节读文件到buf中
		if(ret == -1)
		{
			perror("read");
			return;
		}else if(ret == 0)//读到文件末尾则退出
		{
			printf("EOF\n");
			break;
		}
		//write(fd2,buf,strlen(buf));//写入到fd2对应的文件中
		write(fd2,buf,ret);//写入到fd2对应的文件中
	}

	return ;
}
int main()
{
	int fd1,fd2;
	fd1 = open("福利视频.mp4", O_RDONLY);//以只读方式打开一个文件
	if(fd1 == -1)
	{
		perror("open file fail");
		return -1;
	}
	fd2 = open("copy.mp4", O_WRONLY | O_CREAT | O_TRUNC, 0666);//以只写方式打开一个文件，没有则创建，有则清空
	if(fd2 == -1)
	{
		perror("open file2 fail");
		return -1;
	}
	
	copy_file(fd1,fd2);
	close(fd1);
	close(fd2);
	return 0;
}
