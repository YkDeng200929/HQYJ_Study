#include <stdio.h>
#include <string.h>

int max_of_arr(int *arr)
{
	int max_num = *arr;
	for (int i = 0; i < 5; i++) //有问题，不能用指针衡量数组大小
	{
		if (max_num < *(arr+i))
			max_num = *(arr+i);	
	}

	return max_num;
}

int main(void)
{
	int arr[] = {2,5,7,9};
	
	printf("Max of arry is %d\n", max_of_arr(arr));

	return 0;
}
