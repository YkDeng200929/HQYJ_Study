#include <stdio.h>
#define NAME "lisi"
#define AGE 15+1
#define M 5
#define N 6
#define SUM M+N

int main()
{
	//printf("name:%s\n", NAME);
	//printf("AGE:%d\n", AGE);
	printf("M:%d\n", M);
	printf("N:%d\n", N);
	printf("SUM:%d\n", SUM);
	//宏要原样替换，不要自己给他加括号
	//M+N*M+N = 5+6*5+6 = 41
	printf("ret:%d\n", SUM*SUM);
	printf("ret:%d\n", (SUM)*(SUM));

	return 0;
}

