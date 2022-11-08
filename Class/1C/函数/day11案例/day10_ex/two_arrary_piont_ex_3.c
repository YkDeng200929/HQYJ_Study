#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[3][4];
	int *p = a[0];//&a[0][0]
	int **q = &p;
	int (*funp)[4] = a;//行指针, a <==> &a[0]
	//指针数组，里面存放的列指针
	int *p_arrary[] = {a[0], a[1], a[2], NULL};
	int i = 0, j = 0;
	int len_h = sizeof(a) / sizeof(a[0]);
	int len_l = sizeof(a[0]) / sizeof(a[0][0]);

	for(i = 0; i < len_h; i++)
	{
		for(j = 0; j < len_l; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for(i = 0; i < len_h; i++)
	{
		for(j = 0; j < len_l; j++)
		{
			printf("%d ", a[i][j]);
			//一级指针
			printf("%d ", *(p + i * len_l + j));
			//二级指针
			printf("%d ", *(*q + i * len_l + j));
			//行指针
			printf("%d ", *(*(funp + i) + j));
			printf("%d ", funp[i][j]);
			//指针数组
			printf("%d ", *(p_arrary[i] + j));
			printf("%d ", *(*(p_arrary + i) + j));
			// [] == *()
		}
		putchar('\n');
	}
	
	return 0;
}
