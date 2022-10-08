#include <stdio.h>
#define MONTHS 12
int main(void){
	int day[MONTHS] = {31,28,[4] = 31, 30, 31, [1] = 29};
	int i;

	for (i = 0; i < MONTHS; i++){
		printf("%2d  %d\n", i + 1, day[i]);
	}

	return 0;
}

