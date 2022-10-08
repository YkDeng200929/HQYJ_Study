#include <stdio.h>

int max_of_arr(int arr[], int num)
{
	int max_num = arr[0];
	for (int i = 0; i < num; i++)
	{
		if (max_num < arr[i])
			max_num = arr[i];	
	}

	return max_num;
}

int main(void)
{
	int arr[] = {2,5,7,9};
	printf("Max of arry is %d\n", max_of_arr(arr,sizeof(arr)/sizeof(arr[0])));
	//　记住这个计算数组容量的方法

	return 0;
}
