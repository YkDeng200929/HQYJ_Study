#include <stdio.h>
int donut(int n){
	int count;
	for (count = 0; count < n; count++)
		printf("0\n");
}
int main(void)
{
	int n;
	scanf("%d", &n);
	donut(n);

	return 0;
}
