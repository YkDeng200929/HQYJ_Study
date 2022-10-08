#include <stdio.h>

int max_site(double arr[], int num)
{
	double max = arr[0];
	int sit_max;
	for (int i = 0; i < num; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			sit_max = i;
		}
	}
}

int main(void)
{
	double arr[5] = {1.1,2.2,3.3,4.4,5.5};

	printf("The site of max number is %d\n", max_site(arr,5));

	return 0;
}
