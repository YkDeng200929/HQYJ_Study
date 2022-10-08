// 指针数组是数组，该数组元素为变量地址，而指针数组可以访问数组元素地址所指向的数值 ("字符串数组")
// 数组元素全为指针的数组称为指针数组
// 指针数组就是指向指针的数组
#include <stdio.h>
int main(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int *pi[5] = {&a, &b, &c, &d, &e};
// 根据优先级，[] > *，所以其先定义了一个数组pi[], 然后*解引用后值向数组元素(地址)所指向的值
	printf("This is arry pi:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *pi[i]);
	}
	putchar('\n');

	return 0;
}
