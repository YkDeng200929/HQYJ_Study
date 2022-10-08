#include <stdio.h>

int main(void)
{
	int arr[4][2] = {
		{1,2},
		{3,4},
		{5,6},
		{7,8}
	};

	printf("arr[0] = %p; &arr[0][0] = %p; arr = %p\n", arr[0], &arr[0][0], arr);

	printf("This is arr:\n");

	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", arr[i][j]);
		putchar('\n');
	}

	printf("arr[0] = %d; *arr[0] = %d; arr[0][0] = %d\n", arr[0], *arr[0], arr[0][0]);// 一定要注意，arr[0]存放的是arr[0][0]的地址，不是数组元素

	return 0;
}
