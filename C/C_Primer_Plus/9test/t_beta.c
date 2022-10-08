#include <stdio.h>
void larger_of(double *x, double *y){
	if (*x > *y){
		*y = *x;
	}
	else{
		*x = *y;
	}
}

int main(void)
{
	double number
