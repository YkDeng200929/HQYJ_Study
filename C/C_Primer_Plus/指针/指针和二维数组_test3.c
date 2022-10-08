#include <stdio.h>

int main(void)
{
	int arr[4][5] = {0} ;

	int i, j, k = 0;

	for (i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = k++;
		}
	}

	printf("*(arr + 1): %p\n", *(arr + 1));
	printf("arr[1]: %p\n", arr[1]);
	printf("&arr[1][0]: %p\n", &arr[1][0]);
	printf("**(arr + 1): %d\n", **(arr + 1));
	printf("*(*(arr + 1) + 3): %d\n", **(arr + 1));// 判断是否为arr[1][3]
	printf("arr[1][3] = %d\n", arr[1][3]);

	return 0;
}
