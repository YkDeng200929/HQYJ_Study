#include <stdio.h>

double distance_2num(double arr[], int num)
{
	double max = arr[0];
	double min = arr[0];

	for (int i = 0; i < num; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	for (int i = 0; i < num; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}

	return max-min;
}

int main(void)
{
	double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	printf("The distance of max and min is %.2f\n", distance_2num(arr, sizeof(arr)/sizeof(arr[0])));

	return 0;
}
