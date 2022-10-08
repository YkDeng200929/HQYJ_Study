#include <stdio.h>
double min(double x, double y){
	if (x > y)
		return y;
	else
		return x;
}

int main(void)
{
	double x,y;
	double result;
	scanf("%lf %lf", &x, &y);
	result = min(x,y);
	printf("min is %.2f\n", result);

	return 0;
}
