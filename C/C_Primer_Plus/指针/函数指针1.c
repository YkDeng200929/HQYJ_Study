#include <stdio.h>

// 函数指针就是指向函数的指针
// 指针函数: int *p();
// 函数指针: int (*p)();


int square(int number)
{
	return number*number;
}

int main(void)
{
	int num;
	int (*fp)(int); // 通过函数指针调用函数
	// 解释：指针fp指向的是square一个函数，该函数具有一个int类型的返回值

	printf("请输入一个整数:\n");
	scanf("%d", &num);

	fp = square; // 函数名相当于函数地址

	printf("%d * %d = %d\n", num, num, (*fp)(num));
	// 最后也可以写成fp(num), 不过这样就会让别人误以为fp是一个函数

	return 0;

}


