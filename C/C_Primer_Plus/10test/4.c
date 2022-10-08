#include <stdio.h>

int max_site(double arr[], int num)
{
	double max = arr[0];
	for (int i = 0; i < num; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	for (int i = 0; i < num; i++)
	{
		if (arr[i] == max)
			return i+1; //　注意：数组中数的位置应为标号值加一
	}
}

int main(void)
{
	double arr[5] = {1.1,2.2,3.3,4.4,5.5};

	printf("The site of max number is %d\n", max_site(arr,5));

	return 0;
}
