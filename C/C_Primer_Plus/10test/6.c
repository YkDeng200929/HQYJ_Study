#include <stdio.h>
#define SIZE(x) x

void print_arr(double arr[], int num)
{
	for (int i = 0; i < num; i++)
		printf("%.2f\n", arr[i]);
	putchar('\n');
}

int main(void)
{	
	int x;
	printf("Enter the size of arry:\n");
	scanf("%d", &x);

	double arr[SIZE(x)];
	
	for (int i = 0; i < size; i++)	
	{
		printf("Enter the %d number of arry\n", i+1);
		scanf("%f", arr+i);
	}

	print_arr(arr, size);



	return 0;
}
