#include <stdio.h>
double return_num(double x, double y){
	double dao_x = 1/x;
	double dao_y = 1/y;
	double avry_xy = (dao_x + dao_y)/2;
	return 1/avry_xy;
}

int main(void){
	int a,b;
	printf("Enter two number:\n");
	scanf("%d %d",&a, &b);
	printf("result is %0.2f\n", return_num(a,b));

	return 0;
}

