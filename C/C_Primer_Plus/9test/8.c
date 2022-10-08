#include <stdio.h>
int max (int a, int b, int c){
	int temp;
	if (b > a)
	{
		temp = a;
		a = b;
		b = temp;
		if (a > c)
			return a;
		else
			return c;
	}
	else if (a > c)
		return b;
	else
		return c;
}

int main(void)
{
	int a, b, c,d;
	scanf("%d %d %d", &a, &b, &c);
	d = max(a,b,c);
	printf("max is %d\n", d);

	return 0;
}
