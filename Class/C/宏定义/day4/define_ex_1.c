#include <stdio.h>
#define M 10
#define N 20
#define CALC(T1, T2) (T1 + T2 * T1 - T2)
int main()
{
	int T1, T2;
	printf("(M + N) * M :%d\n", (M + N) * M);
	T1 = M + N;
	T2 = M - N;
	//T1:30
	//T2:-10
	//30 + -10 * 30 - (-10)
	printf("CALC:%d\n", CALC(T1, T2));
	//10 + 20 + 20 - 10  * 10 + 20 - 20 - 10
	printf("CALC:%d\n", CALC(M + N, N - M));
	return 0;
}
