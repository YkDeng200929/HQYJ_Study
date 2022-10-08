#include <stdio.h>

// 算法步骤：
// １、比较相邻的元素，如果前者比后者大，则交换两个元素
// ２、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对
// ３、针对所有的元素重复以上的步骤，除了最后一个
// ４、重复上面三个步骤，直到没有任何一对数字需要比较

// 算法档案：
// 时间复杂度：O(n^2)
// 最优时间复杂度：O(n)
// 平均时间复杂度：O(n^2)
// 空间复杂度：总共O(n)，需要辅助空间 O(1)
// 稳定性：稳定

void bubble_sort(int *arr, int n)
{
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			temp = arr[i+1];
			arr[i+1] = arr[i];
			arr[i] = temp;
		}
	}
}

void print_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}
int main(void)
{
	int arr[8] = {2,6,1,4,7,9,0,3};
	print_arr(arr, 8);
	bubble_sort(arr, 8);
	print_arr(arr, 8);
	

	return 0;
}

