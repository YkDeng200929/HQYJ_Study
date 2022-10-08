#include <stdio.h>

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int calc(int (*fp)(int, int), int num1, int num2)
{
	return (*fp)(num1, num2);
}

/*

 根据优先级和结合律，以下从左往右计算；抛掉select(char op)后变成了
 int (*)(int, int) ---- 一个返回值类型为整形的函数指针；所以函数select返回值为上面的返回值类型为整形的函数指针; 因为优先级的关系，所以写成
 int (*select(char op)(int int))；如果 int (*fp)(int int) select(int, int); 这样写，那么编译器会认为你在一个语句里声明了两个函数

 */
int (*select(char op))(int, int)
{
	switch(op)
	{
		case '+': return add;
		case '-': return sub;
	}
}

int main(void)
{
	int num1, num2;
	char op;
	int (*fp)(int, int);

	printf("请输入一个式子(如 1 + 3):\n");
	scanf("%d%c%d", &num1, &op, &num2);

	fp = select(op);
	printf("%d %c %d = %d\n", num1, op, num2, calc(fp, num1, num2));
	


	return 0;
}
