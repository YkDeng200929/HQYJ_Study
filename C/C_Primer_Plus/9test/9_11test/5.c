#include <stdio.h>
double larger_of(double *x, double *y){
	if (*x < *y)
		*x = *y;
	else
		*y = *x;
}

int main(void)
{
	double x, y;
	printf("Enter:\n");
	scanf("%lf %lf", &x, &y);
	larger_of(&x,&y);
	printf("%.2lf %.2lf", x, y);

	return 0;
}

