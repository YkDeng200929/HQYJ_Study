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

	printf("This is the arry:\n");

	int m, n;

	for (m = 0; m < 4; m++)
	{
		for (n = 0; n < 5; n++)
			printf("%4d ", arr[m][n]);
		putchar('\n');
	}

	printf("*(arr + 1): %p\n", *(arr + 1)); // 指向arr[1][0]的地址
	printf("arr[1]: %p\n", arr[1]); // 指向arr[1]的地址
	printf("&arr[1][0]: %p\n", &arr[1][0]);
	printf("**(arr + 1): %d\n", **(arr + 1));

	return 0;
}
