#include <stdio.h>

int main()
{
	char buf[] = "hello";
	char *p = NULL;

	p = "hello";

	buf[0] = 'w';
	puts(buf);

	//*p = 'w';//error, p所指向的是常量区，只有读权限，不能写


	return 0;
}
