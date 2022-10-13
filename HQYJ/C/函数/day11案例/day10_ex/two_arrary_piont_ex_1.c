#include <stdio.h>
#define M 2
#define N 3

int main(int argc, const char *argv[])
{
	int a[M][N] = {0};
	int  i = 0, j = 0;
#if 0
	for(i = 0; i < sizeof(a) / sizeof(a[0][0]); i++)
	{
		scanf("%d", &a[i / N][ i % N]);
	}
#else
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

#endif

/*
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			//scanf("%d", &a[i][j]);
			//行指针
			scanf("%d", *(a + i) + j);
			//列指针
			scanf("%d", a[i] + j)
		}
	}
*/
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			//printf("%d ", a[i][j]);
			//行指针
			printf("%d ", *(*(a + i) + j));
			//列制作
			printf("%d ", *(a[i] + j));
		}
		putchar('\n');
	}
	
	return 0;
}
