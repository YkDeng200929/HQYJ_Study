#include <stdio.h>

void copy_arr(double *target, double *source, int num)
{
	for (int i = 0; i < num; i++)
	{
		*(target + i) = *(source + i);
	}

}

void copy_ptr(double *target, double *source, int num)
{
	for (int i = 0; i < num; i++)
	{
		*(target + i) = *(source + i);
	}

}
/*
void copy_ptrs(double *target, double *source ,int *(source + 5))
{
	for (int i = 0; i < num; i++)
}
*/
void print_arr(double *ptr)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f", *(ptr + i));
		putchar('\n');
	}
}
int main(void)
{
	double arr1[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double arr2[5];
	double arr3[5];
//	double arr4[5];
	
	copy_arr(arr2, arr1, 5);
	copy_ptr(arr3, arr1, 5);
	
	printf("This is arr2:\n");
	print_arr(arr2);
	printf("This is arr3:\n");
	print_arr(arr3);

	return 0;
}
