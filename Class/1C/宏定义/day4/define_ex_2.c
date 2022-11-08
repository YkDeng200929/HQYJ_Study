#include <stdio.h>

#define WEIGHT 3.0e-23
#define QUART 950
#define WATER_NUM (4 * QUART) / WEIGHT

int main()
{
	printf("WATER_NUM:%f\n", WATER_NUM);
	printf("WATER_NUM:%le\n", WATER_NUM);

	return 0;
}
