#include <stdio.h>

#define M 10 + 2
#define N 8 + 3
#define T 3 - 1
#define DO_CALC(x, y, z) (x * y + z)

int main()
{

	printf("DO_CALC:%d\n", DO_CALC(M, N, T));
	
	return 0;
}
