#include <stdio.h>

int main(void)
{
	int arr[2][3] = {{0,1,2},{3,4,5}};
	int (*p)[3] = arr;// 相当于*arr后的元素，里面有３个元素，所以后面是[3]

	printf("This is arr:\n");

	int i,j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
			if (j == 2)
				putchar('\n');
		}
	}

	printf("(*p)[3] = arr\n");
	/*
	
	putchar('\n');
	printf("**(p+1): %d\n", **(p+1));
	printf("**(arr+1): %d\n", **(arr+1));
	printf("arr[1][0]: %d\n", arr[1][0]);

	putchar('\n');
	printf("*(*(p+1)+2): %d\n", *(*(p+1)+2));
	printf("*(*(arr+1)+2): %d\n", *(*(arr+1)+2));
	printf("arr[1][2]: %d\n", arr[1][2]);

	*/

	putchar('\n');

	printf("p = %p; *p = %p; p[0] = %p\n", p, *p, p[0]);
	printf("**p = %d\n", **p);

	return 0;
}
