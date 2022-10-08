#include <stdio.h>
double h(double num1, double num2){
	double rec1 = 1/num1;
	double rec2 = 1/num2;
	double sum = rec1 + rec2;
	double sum_avg = sum / 2;
	return (1 / sum_avg);

}

int main(void){
	double number1 = 0.0;
	double number2 = 0.0;
	double result = 0.0;

	printf("Enter :\n");
	scanf("%lf", &number1);
	getchar();
	scanf("%lf", &number2);
	getchar();

	result = h(number1, number2);

	printf("result = %f", result);

	return 0;
}
