#include <stdio.h>

/*
 *函数名: Func_add 
 *功能:加法运算
 *参数：int x, int y
 *返回值:int ，返回x, y相加的结果
 */
//x, y --> 形参[形式参数]
int Func_add(int x, int y)
{
	int z = x + y;
	return z;
}
/*函数名:Func_sub
 *功能：减法运算
 *参数：int x, int y
 *返回值：int 返回x, y相减的结果
 */
int Func_sub(int x, int y)
{
	return x - y;
}
/*函数名：Func_mul
 *功能：乘法运算
 *参数：int x, int y
 *返回值:int 返回x, y 相乘的结果
 */
int Func_mul(int x, int y)
{
	return (x * y);
}
/*函数名：Func_div
 *功能：除法运算
 *参数：int x, int y
 *返回值：int 返回x / y的结果
 */
int Func_div(int x, int y)
{
	return x / y;
}

int main(void)
{
	int a = 10, b = 20;
	//int sum;
	//a,b --> 实参[实际参数]
	//传参的本质：赋值 =
	// = : =两边的类型相同
	//sum = Func_add(a, b);
	//printf("sum : %d\n", sum);
	scanf("%d%d", &a, &b);
	printf("add : %d\n", Func_add(a, b));
	printf("sub : %d\n", Func_sub(a, b));
	printf("mul : %d\n", Func_mul(a, b));
	printf("div : %d\n", Func_div(a, b));
	return 0;
}
