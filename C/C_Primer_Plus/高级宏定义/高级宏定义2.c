#include <stdio.h>

//#define SQUARE(x) x * x
#define SQUARE(x) ((x) * (x))  // 所以得加上括号

int main(void)
{
	int x;

	printf("请输入一个整数:\n");
	scanf("%d", &x);

	printf("%d 的平方是 %d\n", x, SQUARE(x));//输入５

//	printf("%d 的平方是 %d\n", x+1, SQUARE(x+1));//输入６结果会是１１，因为此时宏定义不会给 x+1 带括号, 也就是他会看成　x + 1 * x + 1 = 11, 而不是 (x+1) * (x+1)
//
	printf("%d 的平方是 %d\n", x+1, SQUARE(x+1));//加上括号后
	return 0;
}
