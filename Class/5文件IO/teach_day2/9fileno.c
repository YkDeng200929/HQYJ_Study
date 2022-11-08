#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("file","r");

	printf("stdin fileno %d\n",stdin->_fileno);//标准输入，输出和出错对应的文件描述符
	printf("stdout fileno %d\n",stdout->_fileno);
	printf("stderr fileno %d\n",stderr->_fileno);
	printf("fp fileno = %d\n",fp->_fileno);

	return 0;
}
