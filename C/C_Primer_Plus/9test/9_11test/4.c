#include <stdio.h>
double aver(double m, double n){
	double av;
	av = ((1.0/m)+(1.0/n))/2;
	return 1/av;
}

int main(void)
{
	double m,n,result;
	printf("Enter two number:\n");
	scanf("%lf %lf", &m, &n);
	result = aver(m,n);
	printf("%.2lf\n", result);

	return 0;
}
