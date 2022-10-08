#define MSG "I'm special"

#include <stdio.h>

int main(void)
{
	char ar[] = MSG;
	const char *pt = MSG;
	printf("address of \"I'm special\": %p\n", "I'm special");
	printf("            address ar: %p\n", ar);
	// ar 的地址不同
	printf("            address pt: %p\n", pt);
	printf("        address of MSG: %p\n", MSG);
	printf("address of \"I'm special\": %p\n", "I'm special");
	// 证明了静态内存使用的数据与 ar 使用的动态内存不同
	 
	return 0;
}
