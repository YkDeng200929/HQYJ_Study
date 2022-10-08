#include <stdio.h>

int main(void)
{
	int zippo[4][2] = {
		{1,2},
		{3,4},
		{5,6},
		{7,8}
	};

	printf("This is the zippo[4][2]:\n");
	int i,j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", zippo[i][j]);
		putchar('\n');
	}

	int (*pz)[2];
	pz = zippo;// 把zippo的首元素地址(也就是他的每一层)赋给pz,这样(*pz)[2]就相当于一个二维数组
	printf("pz = zippo; (*pz)[2] = zippo[4][2]");

	printf(" pz = %p;  pz + 1 = %p\n", pz, pz + 1);// 比较不同表示方法的元素地址
	printf(" pz[0] = %p;  pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
	printf(" *pz = %p; *pz + 1 = %p\n", *pz, *pz + 1);

	printf(" pz[0][0] = %d\n", pz[0][0]);
	printf(" *pz[0] = %d\n", *pz[0]);
	printf(" **pz = %d\n", **pz);
	printf(" pz[2][1] = %d\n", pz[2][1]);
	printf(" *(*(pz + 2) + 1) = %d\n", *(*(pz + 2) + 1));

	return 0;
}
