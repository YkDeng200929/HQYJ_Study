#include <stdio.h>
double larger_of(double *x, double *y){
	if (*x > *y){
		*y = *x;
	}
	else {
		*x = *y;
	}
}

int main(void){
	double m,n;
	printf("Enter two number:\n");

	scanf("%lf", &m);
	getchar();
	scanf("%lf", &n);
	getchar();

	larger_of(&m, &n);
	printf("now m =  %0.2f, n = %0.2f\n",m, n);

	return 0;
}



