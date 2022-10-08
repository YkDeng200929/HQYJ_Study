#include <stdio.h>

#define R 6371
#define V PI * R * R * R * 4 / 3
#define PI 3.14

//带参数的宏定义
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int main(void)
{
/*	int r;
	float s;

	printf("请输入圆的半径\n");
	scanf("%d", &r);
	s = PI * r * r;
	printf("圆的面积是: %.2f\n", s);
	printf("现在取消宏定义\n");
#undef PI   // 用于取消之前 PI 的定义
	s = PI * r * r;
	printf("圆的面积是: %.2f\n", s);
*/


//	printf("地球的体积大概是: %.2f\n", V);
	

	int x, y;

	printf("请输入两个整数: \n");
	scanf("%d%d", &x, &y);
	printf("%d是较大的数\n", MAX(x, y));

	return 0;
}
