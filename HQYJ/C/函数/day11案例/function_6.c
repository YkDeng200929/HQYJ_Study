#include <stdio.h>

//传参 本质就是 赋值
//x = &a
//y = &b
//地址传递：形参所指向的数据改变，影响实参所指向的数据
void Func_add_point(int *x, int *y)
{
	//10 20
	printf("FC --> *x = %d\t *y = %d\n", *x, *y);

	*x = 30;//*&a --> a
	*y = 40;//*&b --> b

	//30 40
	printf("FC --> *x = %d\t *y = %d\n", *x, *y);

	return ;
}

int main()
{
	int a = 10, b = 20;

	//10 20
	printf("line:%d\ta:%d\tb:%d\n", __LINE__, a, b);

	Func_add_point(&a, &b);
	
	//30 40
	printf("line:%d\ta:%d\tb:%d\n", __LINE__, a, b);

	return 0;
}
