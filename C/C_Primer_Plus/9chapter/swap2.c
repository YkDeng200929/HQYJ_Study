#include <stdio.h>
void interchange(int u, int v){
	int temp;
	
	printf("Origional u = %d and y = %d.\n", u, v);
	temp = u;
	u = v;
	v = temp;
	pritnf("Now u = %d and v = %d.\n", u, v);
}

int main(void)
{
	int x = 5, y = 10;

	printf("Origional x = %d and y = %d.\n", x, y);
	interchange(x, y);
	printf("Now x = %d and y = %d.\n", x, y);

	return 0;
}

