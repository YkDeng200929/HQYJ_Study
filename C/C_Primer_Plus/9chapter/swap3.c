#include <stdio.h>
void interchange(int *u, int *v){
	int temp ;
	temp = *u;
	*u = *v;
	*v = temp;
}


int main(void)
{
	int x = 5, y = 10;
	printf("Origional x = %d, y = %d.\n", x, y);
	interchange(&x, &y);
	printf("Now x = %d, y = %.\n", x, y);

	return 0;
}
