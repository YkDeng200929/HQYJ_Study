#include <stdio.h>
#define PI 3.14

int main()
{
	double area = 0;
	double circle = 0;
	double r = 0;

	scanf("%lf", &r);

	area = PI * r * r;
	circle = 2 * PI * r;

	printf("area:%lf\n", area);
	printf("circle:%lf\n", circle);

	return 0;
}
