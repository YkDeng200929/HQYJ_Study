#include <stdio.h>

int main(void)
{
	printf("Sizeof int is %d\n", sizeof(int));// 4

	int arr1[4][2] = {
		{0,1},
		{2,3},
		{4,5},
		{6,7}
	};

	int arr2[4][3] = {
		{1,3,5},
		{7,9,11},
		{13,15,17},
		{19,21,23}
	};

	printf("sizeof arr1 = %d\n", sizeof(arr1));/* 32因为arr1内含4 * 2 = 8 个int类型的元素,所以总占位数为8 * 4 = 32 */
	printf("sizeof arr2 = %d\n", sizeof(arr2));/* 48因为arr2内含4 * 3 = 12 个nt类型的元素,所以总占位数为12 * 4 = 32 */

	printf("sizeof arr1[0][0] = %d\n", sizeof(arr1[0][0]));
	return 0;
}
