#include <stdio.h>
double min(double x, double y)
{
	if (x > y)
		return y;
	else
		return x;
}
int main(void)
{
	double x, y;
	printf("Enter two number:\n");
	scanf("%lf %lf", &x, &y);
	printf("The min is %.2lf\n", min(x,y));
	
	return 0;
}
