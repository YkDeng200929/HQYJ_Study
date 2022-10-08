#include <stdio.h>

int main(void)
{
	printf("%s, %p, %c\n", "We", "are", *"space farers");
	//第一个打印Ｗe，第二个打印首字母地址，第三个指向首字母

	return 0;
}
