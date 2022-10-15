#include <stdio.h>
//0为假
//非0为真
#define OPEN -1

int main()
{
	//注释：解释代码的语句
#if OPEN
	//OPEN为真，执行11行
	printf("hello\n");
#else
	//OPEN为假，执行14行
	printf("world\n");
#endif

	return 0;
}
